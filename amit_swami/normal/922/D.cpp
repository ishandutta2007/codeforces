#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define int long long
int n,lens,ans;
char s[233333];
pair<int,int> p[233333];
bool cmp(const pair<int,int>& a,const pair<int,int>& b)
{
	return a.first*b.second>a.second*b.first;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1,j,sum;i<=n;++i)
	{
		scanf("%s",s+1);lens=strlen(s+1);
		for(j=1,sum=0;j<=lens;++j)
		{
			if(s[j]=='s')++sum;
			else ans+=sum;
		}
		p[i]=make_pair(sum,lens-sum);
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1,sum=0;i<=n;++i)
	{
		ans+=p[i].second*sum;
		sum+=p[i].first;
	}
	printf("%lld",ans);
	return 0;
}