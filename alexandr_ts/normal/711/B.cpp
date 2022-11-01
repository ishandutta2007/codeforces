#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 501;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

ll a[M][M];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    int pi, pj;
    cin >> n;
    fr(i, n)
        fr(j, n) {
            cin >> a[i][j];
            if (!a[i][j])
                pi = i, pj = j;
        }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    ll sum;
    if (pi == 0)
        sum = accumulate(a[1], a[1] + n, 0ll);
    else
        sum = accumulate(a[0], a[0] + n, 0ll);
    ll ans = sum - accumulate(a[pi], a[pi] + n, 0ll);
    a[pi][pj] = ans;
    fr(i, n)
        if (accumulate(a[i], a[i] + n, 0ll) != sum) {
            cout << -1;
            return 0;
        }
    ll curs = 0;
    fr(i, n)
        curs += a[i][i];
    if (curs != sum) {
        cout << -1;
        return 0;
    }

    curs = 0;
    fr(i, n)
        curs += a[i][n - 1 - i];
    if (curs != sum) {
        cout << -1;
        return 0;
    }

    fr(i, n) {
        curs = 0;
        fr(j, n)
            curs += a[j][i];
        if (curs != sum) {
            cout << -1;
            return 0;
        }
    }
    if (a[pi][pj] <= 0) {
        cout << -1;
        return 0;
    }
    cout << a[pi][pj];
}