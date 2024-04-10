#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        ll s, n, k;
        cin >> s >> n >> k;
        s -= n;
        if (n < k) {
            ll can = k - n;
            if (s != can) cout << "NO\n";
            else cout << "YES\n";
        } else {
            ll cnt = n / k;
            if (k * cnt <= s) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}