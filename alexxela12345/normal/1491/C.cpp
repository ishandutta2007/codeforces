#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

//#define int long long
//
vector<int> arr;
vector<int> nxt;
inline int get(int i) {
    if (i >= (int) arr.size()) {
        return i;
    }
    if (arr[i] != 1) {
        return i;
    }
    return nxt[i] = get(max(i + 1, nxt[i]));
}

void solve() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    int fst = 0;
    nxt.assign(n, 0);
    iota(nxt.begin(), nxt.end(), 0);
    while (true) {
        fst = get(fst);
        if (fst == n) {
            break;
        }
        int cur = fst;
        vector<int> pos = {};
        bool only_last = arr[fst] + fst >= n;
        while (cur < n) {
            pos.push_back(cur);
            cur += arr[cur];
            cur = get(cur);
        }
        if (only_last) {
            int cnt = arr[pos.back()] - max(1, n - 1 - (int) pos.back());
            ans += cnt;
            arr[pos.back()] -= cnt;
        } else {
            ans++;
            for (int el : pos) {
                if (arr[el] > 1) {
                    arr[el]--;
                }
            }
        }
    }
    cout << ans << endl;
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