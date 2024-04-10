#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
            c--;
        }
        vector<int> pos(n);
        vector<vector<int>> gist(n);
        for (int i = 0; i < n; i++) gist[a[i]].pb(i);
        vector<int> b(n, -1);
        vector<int> usd(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (gist[i].empty()) continue;
            ans++;
            b[gist[i][0]] = i;
            pos[i] = gist[i][0];
            usd[i] = 1;
        }
        vector<int> pl;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) pl.pb(i);
        }
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            int j = pl.back();
            pl.pop_back();
            if (i != j) {
                b[j] = i;
                continue;
            }
            b[pos[a[j]]] = i;
            b[j] = a[j];
        }
        cout << ans << "\n";
        for (auto &c : b) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}