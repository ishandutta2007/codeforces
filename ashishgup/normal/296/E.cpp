#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=51;
const int M=201;
const int MOD=1e9+7;

int n, k;
int a[N], f[N];
bool vis[N][N][2];
int cache[N][N][2], cache2[N][N][2][M];

int fact[N], invfact[N];

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

int work()
{
	int ans=0;
	int l1=f[1], l2=f[2];
	while((l1>0 || l2>0) && ans<=200)
	{
		int curk=k;	
		int r1=(f[1]-l1);
		int r2=(f[2]-l2);
		if(r1==0&&l1!=0 || (r1+r2==0))
		{
			while(l1>0 && curk>0)
			{
				l1--;
				curk--;
			}
			while(l2>0 && curk>1)
			{
				l2--;
				curk-=2;
			}
			ans++;
		}
		else
		{
			while(l2>0 && curk>1)
			{
				l2--;
				curk-=2;
			}
			while(l1>0 && curk>0)
			{
				l1--;
				curk--;
			}
			ans++;
		}
		if(l1+l2==0)
			break;
		r1=(f[1]-l1);
		r2=(f[2]-l2);
		if(r1)
		{
			l1++;
			ans++;
		}
		else
		{
			l2++;
			ans++;
		}
	}
	return ans;
}

int dp2(int l1, int l2, int side, int turns)
{
	if(turns==0)
		return ((l1==0)&&(l2==0));
	int &ans=cache2[l1][l2][side][turns];
	if(ans!=-1)
		return ans;
	ans=0;
	if(!side)
	{
		for(int one=0;one<=l1;one++)
		{
			for(int two=0;two<=l2;two++)
			{
				if(one + two*2 > k)
					break;
				if(one + two == 0)
					continue;
				ans += ((nCr(l1, one) * nCr(l2, two)) % MOD) *  dp2(l1-one, l2-two, side^1, turns-1);
				ans%=MOD;
			}
		}
	}
	else
	{
		int r1=f[1]-l1;
		int r2=f[2]-l2;
		for(int one=0;one<=r1;one++)
		{
			for(int two=0;two<=r2;two++)
			{
				if(one + two*2 > k)
					break;
				if(one + two == 0)
					continue;
				ans+=((nCr(r1, one) * nCr(r2, two)) % MOD) * dp2(l1+one, l2+two, side^1, turns-1);
				ans%=MOD;
			}
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>n>>k;
	k/=50;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]/=50;
		f[a[i]]++;
	}
	int ans1=work();
	if(ans1>200)
	{
		cout<<"-1\n0";
		return 0;
	}
	cout<<ans1<<endl;
	int ans2=dp2(f[1], f[2], 0, ans1);
	cout<<ans2;
}