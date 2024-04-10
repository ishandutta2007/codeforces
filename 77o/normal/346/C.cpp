#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5;

int n, t[4 * N];

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1e9;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(v*2, tl, tm, l, min(r, tm)), get(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	cin >> a >> b;
	vector<int> dp(a - b + 1, 1e9);
	vector<int> y(a - b + 1);
	for (int i = 0; i < x.size(); i++) {
		for (int j = a / x[i] * x[i]; j >= b; j -= x[i]) {
			y[a - j] = max(y[a - j], x[i]);
		}
	}
	dp[0] = 0;
	fill(t, t + N * 4, 1e9);
	update(1, 0, N - 1, 0, 0);
	for (int i = 1; i <= a - b; i++) {
		dp[i] = dp[i - 1] + 1;
		if (y[i]) {
			// i - d + 1 .. i - 1
			dp[i] = min(dp[i], get(1, 0, N - 1, max(0, i - y[i] + 1), i - 1) + 1);
		}
		update(1, 0, N - 1, i, dp[i]);
	}
	cout << dp[a - b] << endl;
	return 0;
}