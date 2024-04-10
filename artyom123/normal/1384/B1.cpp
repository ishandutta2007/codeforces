#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<vector<pii>> kek(n);
    bool f = true;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        int mx = min(k, l - d);
        if (mx < 0) {
            f = false;
        }
        if (mx == 0) {
            kek[i].pb(0, 0);
        } else if (mx == k) kek[i].pb(0, 2 * k - 1);
        else {
            kek[i].pb(2 * k - mx, 2 * k - 1);
            kek[i].pb(0, mx);
        }
    }
    if (!f) {
        cout << "No\n";
        return;
    }
    //cout << '!' << endl;
    vector<pii> now;
    now.pb(0, 2 * k - 1);
    for (int i = 0; i < n; i++) {
        vector<pii> tmp;
        if ((int)now.size() == 1) {
            if (now.back().se == 2 * k - 1) {
                if (now.back().fi == 2 * k - 1) tmp.pb(0, 0);
                else {
                    tmp.pb(now.back().fi + 1, 2 * k - 1);
                    tmp.pb(0, 0);
                }
            } else {
                tmp.pb(now.back().fi + 1, now.back().se + 1);
            }
        } else {
            if (now[0].fi == 2 * k - 1) {
                tmp.pb(0, now[1].se + 1);
            } else {
                tmp.pb(now[0].fi + 1, 2 * k - 1);
                tmp.pb(0, now[1].se + 1);
            }
        }
        /*
        cout << "i = " << i << endl;
        cout << "prev" << endl;
        for (auto &c : tmp) cout << c.fi << " " << c.se << endl;
        cout << "cur" << endl;
        for (auto &c : kek[i]) cout << c.fi << " " << c.se << endl;
            */
        now = tmp;
        bool f = false;
        int L = INF;
        for (int j = 0; j < (int)now.size(); j++) {
            int l1 = now[j].fi, r1 = now[j].se, l2 = kek[i][0].fi, r2 = kek[i][0].se;
            //cout << '!' << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if (max(l1, l2) > min(r1, r2)) continue;
            f = true;
            L = min(L, max(l1, l2));
        }
        //cout << f << " " << L << endl;
        if (f) {
            kek[i][0].fi = L;
            now = kek[i];
            continue;
        }
        if ((int)kek[i].size() == 1) {
            cout << "No\n";
            return;
        }
        for (int j = 0; j < (int)now.size(); j++) {
            int l1 = now[j].fi, r1 = now[j].se, l2 = kek[i][1].fi, r2 = kek[i][1].se;
            if (max(l1, l2) > min(r1, r2)) continue;
            f = true;
            L = min(L, max(l1, l2));
        }
        if (f) {
            kek[i][1].fi = L;
            now.clear();
            now.pb(kek[i][1]);
            continue;
        }
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}