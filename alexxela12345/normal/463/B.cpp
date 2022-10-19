#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ldb;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    cout << mx << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/