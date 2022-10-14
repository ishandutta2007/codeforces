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
        vector<int> usd(n + 1);
        vector<int> p;
        for (auto &c : a) {
            if (!usd[c]) p.pb(c);
            usd[c] = 1;
        }
        for (auto &c : p) cout << c << " ";
        cout << "\n";
    }
    return 0;
}