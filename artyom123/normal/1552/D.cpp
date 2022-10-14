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

void gen(vector<vector<int>> &lst, int n, vector<int> &now) {
    if ((int)now.size() == n) {
        lst.pb(now);
        return;
    }
    for (int i = -1; i <= 1; i++) {
        now.pb(i);
        gen(lst, n, now);
        now.pop_back();
    }
}

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
            if (c < 0) c = -c;
        }
        vector<vector<int>> lst;
        vector<int> kek;
        gen(lst, n, kek);
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            for (auto &c : lst) {
                if (c[i] != 0) continue;
                int lol = 0;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    lol += a[j] * c[j];
                }
                if (lol == a[i]) ok = 1;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}