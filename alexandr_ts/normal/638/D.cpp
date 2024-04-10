#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e2 + 10;
const ll MOD = 1e9 + 7;

char a[N][N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, n)
        fr(j, m)
            fr(k1, k)
                cin >> a[i][j][k1];
    int ans = 0;
    fr(i1, n)
        fr(i2, m)
            fr(i3, k) if (a[i1][i2][i3] == '1') {
                bool ok = false;
                if (i1 > 0 && i1 < n - 1 && a[i1 - 1][i2][i3] == '1' && a[i1 + 1][i2][i3] == '1')
                    ok = true;
                if (i2 > 0 && i2 < m - 1 && a[i1][i2 - 1][i3] == '1' && a[i1][i2 + 1][i3] == '1')
                    ok = true;
                if (i3 > 0 && i3 < k - 1 && a[i1][i2][i3 - 1] == '1' && a[i1][i2][i3 + 1] == '1')
                    ok = true;

                if (i1 > 0 && i2 < m - 1 && a[i1 - 1][i2][i3] == '1' && a[i1][i2 + 1][i3] == '1' && a[i1 - 1][i2 + 1][i3] == '0')
                    ok = true;
                if (i1 > 0 && i3 < k - 1 && a[i1 - 1][i2][i3] == '1' && a[i1][i2][i3 + 1] == '1' && a[i1 - 1][i2][i3 + 1] == '0')
                    ok = true;

                if (i2 > 0 && i1 < n - 1 && a[i1][i2 - 1][i3] == '1' && a[i1 + 1][i2][i3] == '1' && a[i1 + 1][i2 - 1][i3] == '0')
                    ok = true;
                if (i2 > 0 && i3 < k - 1 && a[i1][i2 - 1][i3] == '1' && a[i1][i2][i3 + 1] == '1' && a[i1][i2 - 1][i3 + 1] == '0')
                    ok = true;

                if (i3 > 0 && i1 < n - 1 && a[i1][i2][i3 - 1] == '1' && a[i1 + 1][i2][i3] == '1' && a[i1 + 1][i2][i3 - 1] == '0')
                    ok = true;
                if (i3 > 0 && i2 < m - 1 && a[i1][i2][i3 - 1] == '1' && a[i1][i2 + 1][i3] == '1' && a[i1][i2 + 1][i3 - 1] == '0')
                    ok = true;
                ans += ok;
            }
    cout << ans;
}