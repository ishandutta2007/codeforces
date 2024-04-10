#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5, mod = 1e9 + 7;
vector<int> g[maxn];

int bpow(int x, int n)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return bpow(x * x % mod, n / 2);
	else
		return x * bpow(x, n - 1) % mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int g[n] = {0};
    for(int i = 0; i < n - 1; i++)
    {
		int a, b;
		cin >> a >> b;
		g[a - 1]++;
		g[b - 1]++;
	}
	int m = 0;
	for(auto it: g)
		m += it == 1;
	cout << ((n - m) * bpow(2, n - m) + m * bpow(2, n - m + 1)) % mod << endl;
    return 0;
}