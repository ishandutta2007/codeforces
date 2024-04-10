#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e2 + 10;
const ll MOD = 1e9 + 7;

int a[N][N], b[N][N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        fr(j, n) {
            char ch;
            cin >> ch;
            if (ch == 'C')
                a[i][j] = 1;
            b[j][i] = a[i][j];
        }
    int ans = 0;
    fr(i, n) {
        int t = accumulate(a[i], a[i] + n, 0);
        ans += t * (t - 1) / 2;
        t = accumulate(b[i], b[i] + n, 0);
        ans += t * (t - 1) / 2;
    }
    cout << ans;


}