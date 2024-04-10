#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	const int MAXL = 100007;
	char s[MAXL];
	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; )
	{
		while (i < n && s[i] == ' ') i++;
		if (i == n) break;
		
		printf("<");
		if (s[i] == '"')
		{
			i++;
			while (i < n && s[i] != '"') printf("%c", s[i++]);
			i++;
		} else {
			while (i < n && s[i] != ' ') printf("%c", s[i++]);
		}
		printf(">\n");
	}
	return 0;
}