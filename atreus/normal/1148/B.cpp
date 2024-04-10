#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	if (k >= n or k >= m)
		return cout << -1 << endl, 0;
	ll answer = 0;
	for (int i = 1; i <= k + 1; i++){
		int tmp = i - 1;
		ll t = a[i] + ta;
		int idx = lower_bound(b + 1, b + m + 1, t) - b;
		idx += (k - tmp);
		if (idx > m)
			return cout << -1 << endl, 0;
		answer = max(answer, b[idx] + tb);
	}
	cout << answer << endl;
}