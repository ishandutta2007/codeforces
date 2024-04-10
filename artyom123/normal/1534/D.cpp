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
const ll mod = 1e9 + 7;

int main() {
    /*
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    */
    int n;
    cin >> n;
    cout << '?' << " " << 1 << endl;
    vector<int> d(n);
    for (auto &c : d) cin >> c;
    vector<pii> ans;
    int cnt0 = 0, cnt1 = 0;
    for (auto &c : d) {
        if (c % 2 == 0) cnt0++;
        else cnt1++;
    }
    if (cnt0 <= cnt1) {
        for (int v = 0; v < n; v++) {
            if (d[v] == 1) ans.pb(0, v);
            if (d[v] % 2 == 0 && d[v] != 0) {
                cout << '?' << " " << v + 1 << endl;
                for (int i = 0; i < n; i++) {
                    int x;
                    cin >> x;
                    if (x == 1) ans.pb(v, i);
                }
            }
        }
    } else {
        for (int v = 0; v < n; v++) {
            if (d[v] % 2 == 1) {
                cout << '?' << " " << v + 1 << endl;
                for (int i = 0; i < n; i++) {
                    int x;
                    cin >> x;
                    if (x == 1) ans.pb(v, i);
                }
            }
        }
    }
    cout << '!' << "\n";
    for (auto &c : ans) cout << c.fi + 1 << " " << c.se + 1 << "\n";
    cout << endl;
    return 0;
}