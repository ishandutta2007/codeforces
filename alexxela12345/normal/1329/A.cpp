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
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    reverse(l.begin(), l.end());
    vector<int> ans;
    ans.push_back(l[0]);
    int cur_len = l[0];
    for (int i = 1; i < m; i++) {
        int out = max(1LL, l[i] - cur_len);
        cur_len += out;
        ans.push_back(out);
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += l[i];
    }
    if (cur_len > n || sum < n) {
        cout << -1 << endl;
        return 0;
    }
    int cur_add = 0;
    for (int i = 1; i < m; i++) {
        int need = n - cur_len - cur_add;
        int can = l[i] - ans[i];
        int d = min(need, can);
        cur_add += d;
        ans[i] += d;
    }
    vector<int> ans2(m, -1);
    int cur_cnt = 0;
    for (int i = 0; i < m; i++) {
        cur_cnt += ans[i];
        ans2[i] = cur_cnt - l[i] + 1;
    }
    reverse(ans2.begin(), ans2.end());
    for (int i = 0; i < m; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/