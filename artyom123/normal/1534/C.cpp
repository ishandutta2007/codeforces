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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> posa(n), posb(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            posa[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            posb[b[i]] = i;
        }
        vector<int> usd(n);
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            p++;
            int j = i;
            while (!usd[j]) {
                usd[j] = 1;
                j = posa[b[j]];
            }
        }
        ll ans = 1;
        while (p--) {
            ans *= 2;
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}