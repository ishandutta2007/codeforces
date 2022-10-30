#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdlib>
#include <time.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 asdfasdf
#define y1 fdsafdsa

const int maxn = 2000003;

ll fact[maxn], inv[maxn];

ll MOD = 1000000007;

ll binpow(ll x, ll st)
{
	ll ans = 1;
	while (st)
	{
		if (st & 1)
			ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		st >>= 1;
	}
	return ans;
}

ll c(int n, int k)
{
	return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i <= 2000001; i++)
	{
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = binpow(fact[i], MOD - 2);
	}
	
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = n + 1; i <= 2 * n + 1; i++)
		ans = (ans + c(i, i - n)) % MOD;
	cout << ans << "\n";
	
	//cerr << clock() * 1. / CLOCKS_PER_SEC << "\n";//  - curtime << "\n";
	return 0;
}