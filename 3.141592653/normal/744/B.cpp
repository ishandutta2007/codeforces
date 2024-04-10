#include<bits/stdc++.h>
using std::min;
int ans[11][2][1111];
typedef std::vector<int> arrint;
void ask(arrint v)
{
	printf("%llu\n",v.size());
	for(int t:v)printf("%d ",t);
	puts("");
	fflush(stdout);
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(ans,0x3f,sizeof ans);
	for(register int i=0;i<=9;i++)
	{
		std::vector<int>v;
		for(register int ii=1;ii<=n;ii++)
			if((ii>>i)&1)v.push_back(ii);
		if(v.size())
		{
			ask(v);
			for(register int ii=1;ii<=n;ii++)
				scanf("%d",ans[i][1]+ii);
		}
		v.clear();
		for(register int ii=1;ii<=n;ii++)
			if(!((ii>>i)&1))v.push_back(ii);
		if(v.size())
		{
			ask(v);
			for(register int ii=1;ii<=n;ii++)
				scanf("%d",ans[i][0]+ii);
		}
	}
	puts("-1");
	for(register int i=1;i<=n;i++)
	{
		int ansv=1e9;
		for(register int ii=0;ii<=9;ii++)
		{
			if((i>>ii)&1)ansv=min(ansv,ans[ii][0][i]);
			else ansv=min(ansv,ans[ii][1][i]);
		}
		printf("%d ",ansv);
	}
	fflush(stdout);
}