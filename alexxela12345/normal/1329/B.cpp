#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
typedef long long ll;
typedef long double ldb;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        map<int, int> ans;
        ans[1] = 0;
        for (int i = 2; i <= 1e9; i *= 2) {
            ans[i] = ans[i / 2] + (i / 2) * (1 + ans[i / 2]) % m;
            ans[i] %= m;
        }
        int ppow = 1;
        if (d == 1) {
            cout << 1 % m << endl;
            continue;
        }
        while (ppow * 2 <= d) {
            ppow *= 2;
        }
        int k = ans[ppow] + (d - ppow + 1) * (1 + ans[ppow]) % m;
        k %= m;
        cout << k << endl;
    }
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/