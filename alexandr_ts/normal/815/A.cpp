#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 105;
const ld PI = acos(-1);
const int POW = 42;
const ll MOD = 1000 * 1000 * 1000 + 7;

const int N = 1e6 + 5;

int a[M][M], b[M][M];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    frab(i, 1, n)
        fr(j, m)
            b[i][j] = a[i][j] - a[0][j];
    frab(i, 1, n) {
        sort(b[i], b[i] + m);
        if (b[i][0] != b[i][m - 1]) {
            cout << -1;
            return 0;
        }
    }

    int minr = 0, minc = 0;
    fr(i, m)
        if (a[0][i] < a[0][minr])
            minr = i;
    fr(i, n)
        if (a[i][0] < a[minc][0])
            minc = i;
    vector <int> ans;
    fr(i, m)
        if (a[0][i] > a[0][minr]) {
            fr(j, a[0][i] - a[0][minr])
                ans.pb(i);
            int dif = a[0][i] - a[0][minr];
            fr(j, n)
                a[j][i] -= dif;
        }

    fr(i, n)
        fr(j, a[i][0] - a[minc][0]) {
            fr(j, a[i][0] - a[minc][0])
                ans.pb(i + MOD);
            int dif = a[i][0] - a[minc][0];
            fr(j, m)
                a[i][j] -= dif;
        }
    fr(i, n)
        fr(j, m) {
            if (a[i][j] < 0 || a[i][j] != a[0][0]) {
                cout << -1;
                return 0;
            }
        }
    if (n <= m) {
        fr(i, n)
            fr(j, a[0][0])
                ans.pb(i + MOD);
    }
    else {
        fr(i, m)
            fr(j, a[0][0])
                ans.pb(i);
    }

    cout << ans.size() << endl;
    fr(i, ans.size())
        if (ans[i] >= MOD)
            cout << "row " << ans[i] - MOD + 1 << "\n";
        else
            cout << "col " << ans[i] + 1 << "\n";

}