#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;
const int MOD = 998244353;

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

int n, k;
int l[N], r[N];
map<int, vector<int> > event;

int32_t main()
{
	IOS;
	precompute();
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		event[l[i]].push_back(1);
		event[r[i] + 1].push_back(-1);
	}
	int active = 0, ans = 0;
	for(auto &it:event)
	{
		int newCnt = 0;
		for(auto &j:it.second)
			if(j == -1)
				active--;
			else
				newCnt++;
		for(int i = 1; i <= min(k, newCnt); i++)
		{
			if(k - i > active)
				continue;
			int curVal = nCr(newCnt, i) * nCr(active, k - i);
			curVal %= MOD;
			ans += curVal;
			ans %= MOD;
		}
		active += newCnt;
	}
	cout << ans << endl;
	return 0;
}