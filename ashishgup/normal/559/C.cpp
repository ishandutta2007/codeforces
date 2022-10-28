#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=2e5+5;
const int MOD=1e9+7;

int h, w, n;
int fact[N], invfact[N], reach[N], leave[N];
pair<int, int> a[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

int formula(int x1, int y1, int x2, int y2)
{
	if(x1>x2)
		return 0;
	if(y1>y2)
		return 0;
	return nCr(x2-x1+y2-y1, x2-x1);
}

void computedp()
{
	reach[1]=formula(1, 1, a[1].x, a[1].y);
	for(int i=2;i<=n;i++)
	{
		reach[i]=formula(1, 1, a[i].x, a[i].y);
		int subtract=0;
		for(int j=1;j<i;j++)
		{
			subtract+=reach[j]*formula(a[j].x, a[j].y, a[i].x, a[i].y);
			subtract%=MOD;
		}
		reach[i]-=subtract;
		reach[i]+=MOD;
		reach[i]%=MOD;
	}
}

int32_t main()
{
	IOS;
	precompute();
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1, a+n+1);
	computedp();
	int ans=formula(1, 1, h, w);
	int subtract=0;
	for(int i=1;i<=n;i++)
	{
		subtract+=reach[i]*formula(a[i].x, a[i].y, h, w);
		subtract%=MOD;
	}
	ans-=subtract;
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
}