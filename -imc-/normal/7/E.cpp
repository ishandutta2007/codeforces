#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

const int MAX_LINE_LENGTH = 105,
		  MAX_DEFINES     = 105;

void mygets (char* to)
{
	fgets (to, MAX_LINE_LENGTH, stdin);
	int length = strlen (to);
	to[length - 1] = 0;
}

const int TOKEN_EOF          = -1,
		  TOKEN_PLUS         = -2,
		  TOKEN_MINUS        = -3,
		  TOKEN_MUL          = -4,
		  TOKEN_DIV          = -5,
		  TOKEN_LPAREN       = -6,
		  TOKEN_RPAREN       = -7,
		  TOKEN_NUMBER       = -8,
		  TOKEN_CALL_DEFINE  = -9;

const int SAFE_ALL = 0,
		  SAFE_MULBY = 1,
		  SAFE_NONE = 2,
		  SAFE_ERROR = 3;

int defineSafety[MAX_DEFINES];

vector <int> currentLineTokens;
int tokenPosition = 0;
int currentToken;

int nextToken()
{
	return currentToken = currentLineTokens[++tokenPosition];
}

void unget()
{
	currentToken = currentLineTokens[--tokenPosition];
}

map <string, int> defineNameToId;

void splitOnTokens (char* buffer)
{
	int pos = 0;
	while (buffer[pos++] != 'n');
	pos++;

	//printf ("Rest: '%s'\n", buffer + pos);

	bool wasHeader = false;

	while (true)
	{
		while (buffer[pos] == ' ') pos++;
		if (!buffer[pos] || buffer[pos] == '\n') break;

		int theToken = 0;

		if (isalpha (buffer[pos]) || buffer[pos] == '$')
		{
			string token = "";
			while (isalpha (buffer[pos]) || buffer[pos] == '$')
				token += buffer[pos++];

			if (defineNameToId.count (token) > 0)
			{
				theToken = TOKEN_CALL_DEFINE - defineNameToId[token];
			}
			else if (!wasHeader)
			{
				int id = defineNameToId.size();
				defineNameToId[token] = id;
				wasHeader = true;
				continue;
			}
			else
			{
				theToken = TOKEN_NUMBER;
			}
		}
		else if (isdigit (buffer[pos]))
		{
			string token = "";
			while (isdigit (buffer[pos]))
				token += buffer[pos++];

			theToken = TOKEN_NUMBER;
		}
		else
		{
			char c = buffer[pos++];

			theToken = TOKEN_EOF;
			if (c == '+') theToken = TOKEN_PLUS;
			if (c == '-') theToken = TOKEN_MINUS;
			if (c == '*') theToken = TOKEN_MUL;
			if (c == '/') theToken = TOKEN_DIV;
			if (c == '(') theToken = TOKEN_LPAREN;
			if (c == ')') theToken = TOKEN_RPAREN;

			if (theToken == TOKEN_EOF) printf ("Unrecognized: '%c'\n", c);
			assert (theToken != TOKEN_EOF);
		}

		currentLineTokens.push_back (theToken);
	}

	currentLineTokens.push_back (TOKEN_EOF);

	//for (unsigned i = 0; i < currentLineTokens.size(); i++)
	//	printf ("%i ", currentLineTokens[i]);
	//printf ("\n");

	currentToken = currentLineTokens[tokenPosition = 0];
}

int combine (int a, int b, char op)
{
	if (a == SAFE_ERROR || b == SAFE_ERROR)
		return SAFE_ERROR;

	if (op == '+') return SAFE_NONE;
	if (op == '-')
		return b <= SAFE_MULBY ? SAFE_NONE : SAFE_ERROR;

	if (op == '*')
		return (a <= SAFE_MULBY && b <= SAFE_MULBY) ? SAFE_MULBY : SAFE_ERROR;

	if (op == '/')
		return (a <= SAFE_MULBY && b <= SAFE_ALL) ? SAFE_MULBY : SAFE_ERROR;

	assert (!"Impossible");
	return SAFE_ALL;
}

int parseSum();

int parseBase()
{
	if (currentToken == TOKEN_LPAREN)
	{
		nextToken();
		int inside = parseSum();
		if (inside != SAFE_ERROR)
			inside = SAFE_ALL;

		assert (currentToken == TOKEN_RPAREN);
		nextToken();

		return inside;
	}
	else
	{
		if (currentToken == TOKEN_NUMBER)
		{
			nextToken();
			return SAFE_ALL;
		}
		else if (currentToken <= TOKEN_CALL_DEFINE)
		{
			int safe = defineSafety[TOKEN_CALL_DEFINE - currentToken];
			nextToken();
			return safe;
		}
		else
		{
			printf ("Base unrecognized: %i\n", currentToken);
			assert (!"Failure");
		}
	}
}

int parseMul()
{
	int base = parseBase();

	while (currentToken == TOKEN_MUL || currentToken == TOKEN_DIV)
	{
		bool div = currentToken == TOKEN_DIV;
		nextToken();
		int append = parseBase();

		base = combine (base, append, div ? '/' : '*');
	}

	return base;
}

int parseSum()
{
	int base = parseMul();

	while (currentToken == TOKEN_PLUS || currentToken == TOKEN_MINUS)
	{
		bool minus = currentToken == TOKEN_MINUS;
		nextToken();
		int append = parseMul();

		base = combine (base, append, minus ? '-' : '+');
	}

	return base;
}

int parseExpression()
{
	int s = parseSum();
	assert (currentToken == TOKEN_EOF);

	return s;
}

int analyzeDefinition()
{
	int cell = defineNameToId.size() - 1;
	defineSafety[cell] = parseExpression();

	//printf ("Safety of define %i: %i\n", cell, defineSafety[cell]);

	return defineSafety[cell];
}

int main()
{
	char firstLine[MAX_LINE_LENGTH];
	mygets (firstLine);

	int N;
	sscanf (firstLine, "%i", &N);

	for (int i = 0; i < N; i++)
	{
		currentLineTokens.clear();
		tokenPosition = 0;

		char line[MAX_LINE_LENGTH];
		mygets (line);
		splitOnTokens (line);
		analyzeDefinition();
	}

	char expression[MAX_LINE_LENGTH + 15] = "#define $ ";
	mygets (expression + sizeof ("#define $ ") - 1);

	currentLineTokens.clear();
	splitOnTokens (expression);
	int safety = analyzeDefinition();

	printf ("%s\n", safety == SAFE_ERROR ? "Suspicious" : "OK");

	return 0;
}