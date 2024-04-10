#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld double
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n;
ld mx[N],mn[N],sum_a,sum_b,ans[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf",&mx[i]);
	for(int i=0;i<n;i++)scanf("%lf",&mn[i]);
	for(int i=0;i<n;i++)
	{
		ld bb=-mn[i]-mx[i]-sum_a+sum_b,cc=mx[i]-mx[i]*sum_b-mn[i]*sum_b;
		ans[i]=(-bb+(ld)sqrt(abs(bb*bb-4*cc)))/2;
		ld ans1=mn[i]+mx[i]-ans[i];
		sum_a+=ans1;sum_b+=ans[i];
		printf("%.14lf ",ans1);
	}
	puts("");
	for(int i=0;i<n;i++)printf("%.14lf ",ans[i]);
  	return 0;
}