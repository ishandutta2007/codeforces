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
        vector<int> q(n);
        for (auto &c : q) cin >> c;
        vector<int> p(n);
        p[0] = q[0];
        set<int> s;
        for (int i = 1; i <= n; i++) s.insert(i);
        s.erase(p[0]);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (q[i] == q[i - 1]) {
                auto it = s.begin();
                if (*it > q[i]) {
                    ok = false;
                    break;
                }
                p[i] = *it;
                s.erase(it);
                continue;
            } else {
                p[i] = q[i];
                s.erase(p[i]);
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        for (auto &c : p) cout << c << " ";
        cout << "\n";
    }
    return 0;
}