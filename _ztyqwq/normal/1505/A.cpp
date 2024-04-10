#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		if(s == "Is it rated?")
			printf("NO\n");
		else
			printf("YES\n");
		fflush(stdout);
	}
	return 0;
}