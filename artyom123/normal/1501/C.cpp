#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ld long double
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 10;
const int MAXN = 5e6 + 10;

vector<pii> cnt[MAXN];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    map<int, vector<int>> ma;
    for (int i = 0; i < n; i++) ma[a[i]].pb(i);
    vector<pii> ind;
    for (auto &c : ma) {
        if ((int)c.se.size() >= 4) {
            cout << "YES\n";
            cout << c.se[0] + 1 << " " << c.se[1] + 1 << " " << c.se[2] + 1 << " " << c.se[3] + 1;
            return 0;
        }
        if ((int)c.se.size() >= 2) {
            ind.pb(c.se[0], c.se[1]);
        }
        if ((int)ind.size() == 2) {
            cout << "YES\n";
            cout << ind[0].fi + 1 << " " << ind[1].fi + 1 << " " << ind[0].se + 1 << " " << ind[1].se + 1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[a[i] + a[j]].pb(i, j);
            if ((int)cnt[a[i] + a[j]].size() >= 2) {
                for (auto &c : cnt[a[i] + a[j]]) {
                    for (auto &l : cnt[a[i] + a[j]]) {
                        if (c.fi != l.fi && c.fi != l.se && c.se != l.se && c.se != l.fi) {
                            //cout << '!' << " " << a[c.fi] << " " << a[c.se] << " " << a[l.fi] << " " << a[l.se] << endl;
                            cout << "YES\n";
                            cout << c.fi + 1 << " " << c.se + 1 << " " << l.fi + 1 << " " << l.se + 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}