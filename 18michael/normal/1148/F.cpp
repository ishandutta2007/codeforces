#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
LL ans=0,sum=0,sum1;
int a[300002];
LL b[300002];
vector<int> vec[62];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%lld",&a[i],&b[i]),sum+=a[i];
		for(int j=61;~j;--j)
			if((b[i]>>j)&1)
			{
				vec[j].push_back(i);
				break;
			}
	}
	for(int i=0;i<=61;++i)
	{
		sum1=0;
		for(int j=0;j<vec[i].size();++j)sum1+=a[vec[i][j]];
		if(sum1 && (sum>0)==(sum1>0))
		{
			ans|=(1LL<<i);
			for(int j=1;j<=n;++j)if((b[j]>>i)&1)a[j]=-a[j];
		}
	}
	return 0&printf("%lld",ans);
}