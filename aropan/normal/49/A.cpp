#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string s;

int main ()
{
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	char last;
	getline(cin, s);
	for (int i = 0; i < (int)s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z')
			last = s[i];
	}
	
	if ('a' <= last && last <= 'z') last += (int)'A' - (int)'a';
	
	switch (last)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
			puts("YES");
			break;
		default:
			puts("NO");
	}
    return 0;
}