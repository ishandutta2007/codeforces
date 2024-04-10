#include <bits/stdc++.h>

using namespace std;
#define int long long
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
const int INF = 1e9 + 7;

signed main() {
    int t;
    cin >> t;
    for (int u = 0; u < t; ++u) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (n == 3) {
            if (a == 1 && b == 3) {
                if (x != 1) {
                    cout << 2 << "\n";
                }
                else {
                    cout << 1 << "\n";
                }
            }
            else {
                cout << 2 << "\n";
            }
            continue;
        }
        while (x > 0 && b < n) {
            ++b;
            --x;
        }
        while (x > 0 && a > 1) {
            --a;
            --x;
        }
            cout << b - a << "\n";
    }
}