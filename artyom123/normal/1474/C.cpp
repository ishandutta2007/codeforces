#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (auto &c : a) cin >> c;
        sort(all(a));
        for (int i = 2 * n - 2; i >= 0; i--) {
            vector<pii> ans;
            int start_x = a[2 * n - 1] + a[i];
            ans.pb(a[2 * n - 1], a[i]);
            vector<int> usd(2 * n);
            usd[2 * n - 1] = usd[i] = 1;
            int j = 2 * n - 1;
            int x = start_x;
            map<int, vector<int>> ma;
            for (int j = 0; j < 2 * n - 1; j++) if (j != 2 * n - 1 && j != i) ma[a[j]].pb(j);
            while ((int)ans.size() < n) {
                x = ans.back().fi;
                while (usd[j]) j--;
                usd[j] = 1;
                ma[a[j]].pop_back();
                int k = -1;
                if (ma[x - a[j]].size()) {
                    k = ma[x - a[j]].back();
                    ma[x - a[j]].pop_back();
                }
                if (k >= 0) usd[k] = 1;
                if (k >= 0 && a[k] + a[j] == x) ans.pb(a[j], a[k]);
                else break;
            }
            if (ans.size() == n) {
                cout << "YES\n";
                cout << start_x << "\n";
                for (auto &c : ans) cout << c.fi << " " << c.se << "\n";
                break;
            }
            if (i == 0) {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
/*
1
5
1 2 3 4 5 6 7 14 3 11
*/