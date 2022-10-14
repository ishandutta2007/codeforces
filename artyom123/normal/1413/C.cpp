#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ld long double
#define pb emplace_back
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    vector<int> a(6);
    for (auto &c : a) cin >> c;
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &c : b) cin >> c;
    vector<pii> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            l.pb(b[i] - a[j], i);
        }
    }
    sort(all(l));
    vector<vector<int>> gist(n);
    int mx = -1;
    for (int i = 0; i < (int)l.size(); i++) {
        gist[l[i].se].pb(i);
        if ((int)gist[l[i].se].size() == 1) mx = max(mx, l[i].fi);
    }
    vector<int> p(n, 0);
    int ans = INF;
    for (int i = 0; i < (int)l.size(); i++) {
        ans = min(ans, mx - l[i].fi);
        if (p[l[i].se] == 5) break;
        p[l[i].se]++;
        mx = max(mx, l[gist[l[i].se][p[l[i].se]]].fi);
    }
    cout << ans;
    return 0;
}