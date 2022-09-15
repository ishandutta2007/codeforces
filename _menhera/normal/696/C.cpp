#include<cstdio>
const int MOD = 1e9+7;
int pow(int a, long long b)
{
	if(b==1) return a;
	if(b==0) return 1;
	long long ans = pow(a, b/2);
	ans *= ans;
	ans %= MOD;
	if(b&1)
	{
		ans *= a;
		ans %= MOD;
	}
	return ans;
}
int main()
{
	int inv3 = pow(3, MOD-2);
	int inv6 = pow(6, MOD-2);
	int inv2 = pow(2, MOD-2);
	int k;
	scanf("%d",&k);
	int m1=MOD-1;
	int p2=2;
	for(int i=0; i<k; i++)
	{
		long long t;
		scanf("%lld",&t);
		m1 = pow(m1, t);
		p2 = pow(p2, t);
	}
	printf("%d/%d",(int)((1LL*p2*inv6+1LL*m1*inv3)%MOD)  ,(int)((1LL*p2*inv2)%MOD));
	return 0;
}