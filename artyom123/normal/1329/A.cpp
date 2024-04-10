#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

const bool IS_MULTITEST = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    long long del = 0;
    vector<pair<int, int>> l(m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> l[i].fi; l[i].se = i; sum += l[i].fi;
    }
    if (sum < n) {
        cout << -1; return;
    }
    del = sum - n;
    vector<int> p(m);
    p[l[0].se] = 1;
    vector<long long> pos(m);
    pos[0] = 1;
    for (int i = 1; i < m; i++) {
        int now = max(pos[i - 1] + 1, pos[i - 1] + l[i - 1].fi - del);
        if (now + l[i].fi > n + 1) {
            cout << -1; return;
        }
        del -= (pos[i - 1] + l[i - 1].fi - now);
        pos[i] = now;
        p[l[i].se] = now;
    }
    if (del == 0) {
        for (auto &c : p) cout << c << " ";
    } else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    if (IS_MULTITEST) cin >> t;
    else t = 1;
    while (t--) solve();
    return 0;
}