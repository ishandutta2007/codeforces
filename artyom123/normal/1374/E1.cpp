#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b, c;
        for (int i = 0; i < n; i++) {
            int t, f, s;
            cin >> t >> f >> s;
            if (f == 1 && s == 1) a.pb(t);
            if (f == 1 && s == 0) b.pb(t);
            if (f == 0 && s == 1) c.pb(t);
        }
        sort(all(a));
        sort(all(b));
        sort(all(c));
        vector<int> pra(1), prb(1), prc(1);
        for (auto &l : a) {
            int x = pra.back();
            pra.pb(x + l);
        }
        for (auto &l : b) {
            int x = prb.back();
            prb.pb(x + l);
        }
        for (auto &l : c) {
            int x = prc.back();
            prc.pb(x + l);
        }
        int ans = INF;
        for (int i = 0; i <= k && i <= (int)a.size(); i++) {
            int lol = k - i;
            if (lol > (int)b.size() || lol > (int)c.size()) continue;
            ans = min(ans, pra[i] + prb[lol] + prc[lol]);
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}