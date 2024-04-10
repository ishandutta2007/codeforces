#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e6;

int bpow(int x, int n, int m)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return bpow(x * x % m, n / 2, m);
	else
		return x * bpow(x, n - 1, m) % m;
}

int order(int a, int q)
{
	int cur = 1;
	for(int i = 1; i < maxn; i++)
	{
		cur = cur * a % q;
		if(cur == 1)
			return i;
	}
	assert(false);
}

int fact[maxn], rfact[maxn];
int nCr(int n, int r, int m)
{
	if(n < r)
		return 0;
	//cout << n << ' ' << r << ':' << fact[n] << ' ' << fact[r] << ' ' << fact[n - r] << endl;
	return fact[n] * rfact[r] % m * rfact[n - r] % m;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, q;
    cin >> n >> m >> a >> q;
    int ord = order(a, q);
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
		fact[i] = fact[i - 1] * i % ord;
		rfact[i] = bpow(fact[i], ord - 2, ord);
	}
	int ans[n] = {0};
	for(int i = 0; i < n; i++)
	{
		if(i > 0)
			ans[i] = ans[i - 1];
		ans[i] = (ans[i] + nCr(m, i, ord)) % ord;
	}
	cout << endl;
	reverse(ans, ans + n);
	for(auto it: ans)
		cout << bpow(a, it, q) << ' ';
    return 0;
}