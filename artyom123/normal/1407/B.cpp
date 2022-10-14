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
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[ind]) ind = i;
        }
        vector<int> usd(n), b;
        b.pb(a[ind]);
        usd[ind] = 1;
        int cur = a[ind];
        for (int i = 0; i < n - 1; i++) {
            int ind = -1;
            for (int j = 0; j < n; j++) {
                if (usd[j]) continue;
                if (ind == -1 || __gcd(a[j], cur) > __gcd(a[ind], cur)) ind = j;
            }
            b.pb(a[ind]);
            usd[ind] = 1;
            cur = __gcd(cur, a[ind]);
        }
        for (auto &c : b) cout << c << " ";
        cout << "\n";
    }
    return 0;
}