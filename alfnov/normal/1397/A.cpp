#include<bits/stdc++.h>
using namespace std;
char s[1005];
int gs[30];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(gs,0,sizeof(gs));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			int ll=strlen(s+1);
			for(int j=1;j<=ll;j++)gs[s[j]-'a']++;
		}
		int flag=1;
		for(int i=0;i<26;i++)if(gs[i]%n)
		{
			puts("NO");
			flag=0;
			break;
		}
		if(flag)puts("YES");
	}
	return 0;
}