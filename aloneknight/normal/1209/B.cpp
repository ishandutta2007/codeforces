#include<bits/stdc++.h>
using namespace std;
int n,cc,t[1005];char s[105];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		int a,b,o=s[i]-'0';scanf("%d%d",&b,&a);
		for(int j=0;j<150;j++)
		{
			if(j>=a&&(j-a)%b==0)o^=1;
			t[j]+=o;
		}
	}
	int ans=0;
	for(int i=0;i<150;i++)ans=max(ans,t[i]);
	printf("%d\n",ans);
	return 0;
}