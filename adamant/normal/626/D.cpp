#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

const int maxn = 5e3 + 42;
int cnt_p[2 * maxn];
int cnt_pp[2 * maxn];

signed main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int64_t n;
	cin >> n;
	int64_t a[n];
	for(auto &it: a)
		cin >> it;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			cnt_p[a[j] - a[i]]++;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			cnt_pp[i + j] += cnt_p[i] * cnt_p[j];
	for(int i = 1; i < 2 * maxn; i++)
		cnt_pp[i] += cnt_pp[i - 1];
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			ans += cnt_pp[a[j] - a[i] - 1];
	double d = n * (n - 1) / 2.;
	cout << fixed << setprecision(9) << ans / d / d / d << "\n";
	return 0;
}