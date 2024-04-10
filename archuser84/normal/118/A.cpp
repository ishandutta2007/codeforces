#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
	switch(tolower(c))
	{
	case 'a': return true;
	case 'e': return true;
	case 'i': return true;
	case 'o': return true;
	case 'u': return true;
	case 'y': return true;
	default: return false;
	}
}

int main()
{
	char s[110];
	cin >> s;
	int l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (!isVowel(s[i]))
			printf(".%c", tolower(s[i]));
	}
	cout << endl;
}