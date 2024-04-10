#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll
#ifndef LOCAL
#define endl '\n'
#endif

#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())


void solve() {
unordered_map<ll, int> cnt;
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
        sm += x;
    }
    deque<int> q;
    q.push_back(sm);
    int cntt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        cntt++;
        if (cnt[x]) {
            cnt[x]--;
            continue;
        } else if (x == 1) {
            cout << "No" << endl;
            return;
        } else {
            q.push_front((x + 1) / 2);
            q.push_front((x) / 2);
        }
    }
    cout << "Yes" << endl;
#ifdef LOCAL
    cout << cntt << endl;
#endif
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}