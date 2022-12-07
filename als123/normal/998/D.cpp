#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
LL n;
//vector<LL> a;
int main()
{
	scanf("%lld",&n);
	LL ans=0;
	for (LL u=0;u<=8;u++)
		for (LL i=0;i<14;i++)
			if (u+i<=n)
			{
				if (u>=1&&i>=5) continue;
				LL lalal=0;
				LL t=(n-u-i);
				/*for (LL j=0;j<=t;j++)
				{
					lalal=j*50+i*10+u*5+(n-u-i-j);
					if (u==8&&j>=1) continue;
					if (lalal==176) printf("%lld %lld %lld\n",u,i,j);
					a.push_back(lalal);
				}*/
				if (u==8) ans++;
				else ans=ans+t+1;
			}
	//sort(a.begin(),a.end());
	//LL t=a.size();
	/*for (int u=1;u<t;u++)
		if (a[u]==a[u-1])
			printf("%d\n",a[u]);*/
	printf("%lld\n",ans);
	return 0;
}