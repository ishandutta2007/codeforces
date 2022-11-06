#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[500005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),mn=26;
	for(int i=1;i<=n;i++)
	{
		int c=s[i]-'a';
		if(mn<c)puts("Ann");
		else mn=c,puts("Mike");
	}
	return 0;
}