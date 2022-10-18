#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double
typedef double ftype;
typedef complex<double> point;
#define x real
#define y imag

vector<int> primes(int m)
{
	vector<int> ans;
	for(int i = 2; i * i <= m; i++)
		if(m % i == 0)
		{
			ans.push_back(i);
			while(m % i == 0)
				m /= i;
		}
	if(m != 1)
		ans.push_back(m);
	return ans;
}

int phi(int m)
{
	auto pr = primes(m);
	for(auto p: pr)
		m = m / p * (p - 1);
	return m;
}

const int maxn = 3e5;
vector<int> ans[maxn];

int bpow(int x, int n, int m)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return bpow(x * x % m, n / 2, m);
	else
		return x * bpow(x, n - 1, m) % m;
}

vector<int> solve(int *a, int n, int m)
{
	auto pr = primes(m);
	for(int d = 1; d <= m; d++)
		if(m % d == 0)
		{
			int p = m / d;
			for(int j = 0; j < d; j++)
				if(__gcd(j, d) == 1 && binary_search(a, a + n, p * j) == 0)
					ans[d].push_back(p * j);
			vector<int> cur;
			for(auto pk: pr)
				if(d % pk == 0 && ans[d / pk].size() > cur.size())
					cur = ans[d / pk];
			for(auto it: cur)
				ans[d].push_back(it);
		}
	int ph = phi(m);
	for(int i = ans[m].size() - 1; i > 0; i--)
	{
		int g = __gcd(ans[m][i - 1], ans[m][i]);
		int A = ans[m][i - 1] / g;
		int B = ans[m][i] / g;
		ans[m][i] = B * bpow(A, ph - 1, m) % m;
	}
	return ans[m];
}

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	auto ans = solve(a, n, m);
	cout << ans.size() << endl;
	for(auto it: ans)
		cout << it << ' ';
	for(int i = 1; i < ans.size(); i++)
		ans[i] = ans[i] * ans[i - 1] % m;
	return 0;
}