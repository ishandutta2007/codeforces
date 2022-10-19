#include<bits/stdc++.h>
using namespace std;
int mp[25][25];
char s[100005],t[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=20;i++)for(int j=1;j<=20;j++)
			mp[i][j]=0;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]>t[i])
			{
				flag=0;
				break;
			}
			mp[s[i]-'a'+1][t[i]-'a'+1]=1;
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=20;i++)
		{
			int w=0;
			for(int j=i+1;j<=20;j++)if(mp[i][j])
			{
				w=j;
				break;
			}
			if(!w)continue;
			ans++;
			for(int j=w;j<=20;j++)mp[w][j]|=mp[i][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}