#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = (1 << 22) + 20;
const int maxm = 5e3 + 20;

int t[maxn * 4] , l[maxm] , r[maxm] , val[maxn] , k , fen[maxn];

string s , res;

bool is[maxn];

void flip(int p)
{
	int val = (is[p]? -1 : 1);
	is[p] ^= 1;

	for(p += 5; p < maxn; p += lb(p))
		fen[p] += val;
}

int getKth(int val)
{
	int res = 0;
	for(int i = 22; i >= 0; i--)
		if(fen[res ^ (1 << i)] <= val)
		{
			res ^= (1 << i) , val -= fen[res];
		}

	return res - 4;
}

void solve(int n , int k)
{
	if(n < 0)
	{
		for(int i = 0; i < k; i++)
		{
			int pos = getKth(i);
			res[pos] = s[i];
		}
		return;
	}

	int len = r[n] - l[n] + 1;
	int L = l[n] + len , R = r[n] + len;

	int eshterak = max(0 , min(R , k - 1) - max(L , 0) + 1);
	if(!eshterak)
	{
		solve(n - 1 , k);
		return;
	}

	vector<int> inds;
	for(int i = 0; i < eshterak; i++)
	{
		inds.pb(getKth(i + L));
	}

	for(auto x : inds)
		flip(x);

	solve(n - 1 , k - eshterak);

	for(auto x : inds)
		flip(x); 

	val[0] = 1;
	for(int i = 0; i < eshterak; i++)
	{
		if(i)
			val[i] = val[i - 1] + 2;
		if(val[i] >= len)
			val[i] = 0;

		int pos = getKth(l[n] + val[i]);
		res[getKth(i + L)] = res[pos];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> s >> k >> n;
	res.resize(k);

	for(int i = 0; i < k; i++)
		flip(i);

	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i] , l[i]-- , r[i]--;

	solve(n - 1 , k);
	cout << res << endl;
}