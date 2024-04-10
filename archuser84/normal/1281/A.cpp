#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int main()
{
	int t;
	char s[100][2000];
	cin >> t;
	for (Loop)
		cin >> s[loop];
	for (Loop)
	{
		switch (s[loop][strlen(s[loop])-1])
		{
		case 'u': cout << "JAPANESE\n"; break;
		case 'o': cout << "FILIPINO\n"; break;
		case 'a': cout << "KOREAN\n"; break;
		}
	}
}