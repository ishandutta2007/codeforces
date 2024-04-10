#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define int int64_t
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define SZ(x) (int)(x).size()

long long l, r, k;

void fin()
{
    long long n = l + (l & 1);
	cout << 1 << '\n' << 2 << '\n' << n << ' ' << n+1 << '\n';
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> r >> k;

	if (r - l <= 10) {
        int maxMask = 1 << (r-l+1);
        long long best = 1e18;
        int bestMask = -1;

        for (int mask = 1; mask < maxMask; ++mask) {
            if (__builtin_popcount(mask) > k) continue;

            long long cur = 0;
            for (long long i = l; i <= r; ++i) {
                if (mask >> (i - l) & 1) cur ^= i;
            }
            if (cur < best) {
                best = cur;
                bestMask = mask;
            }
        }

        cout << best << '\n' << __builtin_popcount(bestMask) << '\n';
        for (long long i = l; i <= r; ++i) {
			if (bestMask >> (i - l) & 1) cout << i << ' ';
        }
        cout << '\n';
        return 0;
	}

    if (k == 1) {
        cout << l << '\n' << 1 << '\n' << l << '\n';
    } else if (k == 2) {
    	fin();
    } else if (k == 3) {
    	int bits; bool found = 0;

        for (bits = 45; bits >= 0 && !found; --bits) {
            if (l < (1ll << bits) && (1ll << bits) <= r) found = 1;
        }
        ++bits;

        if (!found) fin();

		long long tmp = r - (1ll << bits);

        int tbits = 0;
        while ((1ll << tbits) <= tmp) ++tbits;
        long long mx = (1ll << tbits) - 1;
        long long tmp2 = tmp ^ mx;
//        assert(tmp2 < tmp);

        if (mx < l) fin();

        cout << 0 << '\n' << 3 << '\n';
        cout << mx << ' ' << (tmp ^ (1ll << bits)) << ' ' << (tmp2 ^ (1ll << bits)) << '\n';

    } else {
    	long long n = l + (l & 1);
        cout << 0 << '\n' << 4 << '\n';
        cout << n << ' ' << n+1 << ' ' << n+2 << ' ' << n+3 << '\n';
    }
}