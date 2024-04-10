#include<bits/stdc++.h>
using namespace std;
char s[2000005];
int ne[2000005],vist[2000005],ttt[2000005];
char ou[2000005];
int main()
{
	int n,k;
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=2;i<=n;i++)
	{
		int r=ne[i-1];
		while(r)
		{
			if(s[r+1]==s[i])
			{
				ne[i]=r+1;
				break;
			}
			r=ne[r];
		}
		if(!r&&s[1]==s[i])ne[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		int r=ne[i],tot=0;
		while(r)
		{
			ttt[++tot]=r;
			int tt=i/(i-r);
			if(tt<k)break;
			if(tt==k||i==1ll*(k+1)*(i-r))
			{
				vist[i]=1;
				break;
			}
			r=ne[r];
		}
		for(int j=1;j<=tot;j++)ne[ttt[j]]=min(ne[ttt[j]],r);
	}
	if(k==1)for(int i=1;i<=n;i++)vist[i]=1;
	for(int i=1;i<=n;i++)ou[i]=vist[i]+'0';
	printf("%s\n",ou+1);
	return 0;
}