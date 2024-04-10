#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

const int INF = 1e8;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    bool hasQ = 0, has0 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == q) hasQ = 1;
		if (a[i] == 0) has0 = 1;
    }

    if (!hasQ && !has0) {
		cout << "NO" << endl;
		return 0;
    }
    for (int i = 0; i < n && !hasQ; ++i) {
        if (a[i] == 0) {
			a[i] = q;
			hasQ = 1;
        }
    }

    for (int i = 1; i <= n-1; ++i) {
		if (a[i-1] != 0 && a[i] == 0) a[i] = a[i-1];
    }
    for (int i = n-1; i >= 1; --i) {
		if (a[i] != 0 && a[i-1] == 0) a[i-1] = a[i];
    }

    if (a[0] == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) cout << q << " ";
		cout << endl;
		return 0;
    }

    int s[q+1], e[q+1], l[n];
    for (int i = 1; i <= q; ++i) {
        s[i] = INF;
        e[i] = -INF;
    }
    for (int i = 0; i < n; ++i) {
        if (s[a[i]] == INF) s[a[i]] = i;
        e[a[i]] = i;
    }

    l[0] = -1;
    for (int i = 1; i < n; ++i) {
        l[i] = i-1;
        while (l[i] >= 0 && a[l[i]] >= a[i]) l[i] = l[l[i]];
    }

    for (int i = 1; i <= q; ++i) {
		if (s[i] == INF) continue;
        if (l[e[i]] >= s[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
}