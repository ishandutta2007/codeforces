#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 102;

int a[N], b[N], c[N];
int d[N][N][N * N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        cin >> b[i];
        c[i] = b[i];
    }

    sort(c, c + n);
    reverse(c, c + n);
    int k = 0, cursum = 0;
    int sum = accumulate(a, a + n, 0);
    fr(i, n) {
        cursum += c[i];
        k++;
        if (cursum >= sum)
            break;
    }

    int sumb = accumulate(b, b + n, 0);

    fr(i, n + 1)
        fr(j, k)
            fr(s, sumb + 1)
                d[i][j][s] = -INF;
    d[0][0][0] = 0;

    fr(i, n)
        fr(j, k + 1)
            fr(s, sumb + 1)
                if (d[i][j][s] != -INF) {
                    d[i + 1][j][s] = max(d[i + 1][j][s], d[i][j][s]);
                    d[i + 1][j + 1][s + b[i]]  = max(d[i + 1][j + 1][s + b[i]],
                        d[i][j][s] + a[i]);
                }

    int mx = 0;
    frab(i, sum, sumb + 1)
        mx = max(mx, d[n][k][i]);

    cout << k << " " << sum - mx;


}