#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1e3 + 3;
const int N = 105;

ld a[N][N];
int n1;

ld cnt[N][N];
ll mask[N][N];
ld p[N][N];
vector <int> g[N];

void f(int n, int v) {
    if (n == 1) {
        cnt[v][2 * v - n1] = a[2 * v - n1][2 * v + 1 - n1] / 100.;
        p[v][2 * v - n1] = a[2 * v - n1][2 * v + 1 - n1] / 100.;
        //mask[v][2 * v] = 0;
        cnt[v][2 * v + 1 - n1] = a[2 * v - n1 + 1][2 * v - n1] / 100.;
        p[v][2 * v - n1 + 1] = a[2 * v - n1 + 1][2 * v - n1] / 100.;
        //mask[v][2 * v + 1] = 1;
        g[v].pb(2 * v - n1);
        g[v].pb(2 * v + 1 - n1);
        return;
    }

    f(n - 1, v * 2);
    f(n - 1, v * 2 + 1);

    for (auto p1: g[2 * v])
        for (auto p2: g[2 * v + 1]) {
            p[v][p1] += p[2 * v][p1] * p[2 * v + 1][p2] * a[p1][p2] / 100;
            p[v][p2] += p[2 * v][p1] * p[2 * v + 1][p2] * a[p2][p1] / 100;
        }

    for (auto p1: g[2 * v])
        for (auto p2: g[2 * v + 1]) {
            //int newmask = ((mask[2 * v + 1][p2] << (n - 1)) + mask[2 * v][p1]) * 2;
            if (cnt[v][p1] < cnt[2 * v][p1] + cnt[2 * v + 1][p2] + p[v][p1] * (1 << (n - 1))) {
                cnt[v][p1] = cnt[2 * v][p1] + cnt[2 * v + 1][p2] + p[v][p1] * (1 << (n - 1));
                //mask[v][p1] = newmask;
            }
            if (cnt[v][p2] < cnt[2 * v][p1] + cnt[2 * v + 1][p2] + p[v][p2] * (1 << (n - 1))) {
                cnt[v][p2] = cnt[2 * v][p1] + cnt[2 * v + 1][p2] + p[v][p2] * (1 << (n - 1));
                //mask[v][p2] = newmask + 1;
            }
        }


    for (auto t: g[2 * v])
        g[v].pb(t);
    for (auto t: g[2 * v + 1])
        g[v].pb(t);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    n1 = (1 << n);
    fr(i, (1 << n))
        fr(j, (1 << n))
            cin >> a[i][j];

    f(n, 1);

    ld ans = 0;
    fr(i, (1 << n))
        ans = max(ans, cnt[1][i]);
    cout << fixed << setprecision(12) << ans;
}