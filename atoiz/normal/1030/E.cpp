#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
	long long a[n+2];
	a[0] = 0;

	int even = 1, odd = 0, tmp = 0;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
		a[i] = __builtin_popcountll(a[i]);
		tmp = (tmp + (a[i] & 1)) & 1;

		if (tmp) ++odd;
		else ++even;
	}

    long long ans = (even * (even - 1ll) + odd * (odd - 1ll)) / 2ll;

    for (int l = 1; l <= n; ++l) {
        int su = 0, mx = 0;
        for (int r = l; r <= min(l + 200, n); ++r) {
            su += a[r];
            mx = max(a[r], 1ll * mx);
            if (su % 2 == 0 && mx * 2 > su) --ans;
        }
    }

    cout << ans;
}