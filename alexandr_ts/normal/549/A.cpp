#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;
const double EPS = 1;
const double MIN1 = 11.531;
const double MIN2 = 11.533;
const double MIN3 = 10.398;
const double MIN4 = 10.4;
const double ST = 0.00001;

char a[N][N];
char be[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    fr(i, n - 1)
        fr(j, m - 1) {
            fill(be + (int)'a', be + (int)'a' + 26, false);
            be[a[i][j]] = be[a[i + 1][j]] = be[a[i][j + 1]] = be[a[i + 1][j + 1]] = true;
            if (be['f'] && be['a'] && be['c'] && be['e'])
                ans++;
        }
    cout << ans;

}