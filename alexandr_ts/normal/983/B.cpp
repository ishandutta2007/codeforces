#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-14;
const ld PI = acos(-1);
const ll M = 1e3 + 10;
const int N = 5010;

int a[N];
int f[N][N], dp[N][N];

void solve() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    for (int len = 1; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = a[l];
            }
            else {
                f[l][r] = f[l][r - 1] ^ f[l + 1][r];
            }
        }

    for (int len = 1; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = f[l][r];
            if (len > 1) {
                dp[l][r] = max(dp[l + 1][r], dp[l][r]);
                dp[l][r] = max(dp[l][r - 1], dp[l][r]);
            }
        }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << "\n";
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();

}