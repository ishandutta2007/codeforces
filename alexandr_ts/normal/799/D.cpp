#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5;
const int M = 37;

ll ar[N + 10];
ll pref[N + 10];

bool d[M][N + 10];

ll solve(ll h, ll w, ll a, ll b, int len) {
    fr(ans, len + 1) {
        fr(j, len + 1)
            fr(j1, N + 1)
                d[j][j1] = false;
        d[0][1] = true;
        fr(i, ans)
            fr(j, N + 1)
                if (d[i][j]) {
                    d[i + 1][j] = true;
                    if ((ll)j * ar[i] <= N)
                        d[i + 1][(ll)j * ar[i]] = true;
                }
        fr(j, N + 1)
            if (d[ans][j]) {
                ll val1 = 1;
                bool ok = false;
                fr(i, ans) {
                    val1 *= ar[i];
                    if (val1 >= (ll)j * (ll)100000) {
                        ok = true;
                        break;
                    }
                }
                if (h * (ll)j >= a && (ok || pref[ans] / (ll)j * w >= b) || h * (ll)j >= b && (ok || pref[ans] / (ll)j * w >= a)) return ans;
                if (ans < len)
                    if (h * (ll)j * ar[ans] >= a && (ok || pref[ans] / (ll)j * w >= b) || h * (ll)j * ar[ans] >= b && (ok || pref[ans] / (ll)j * w >= a)) return ans + 1;
                if (ans < len)
                    if (h * (ll)j >= a && (ok || pref[ans] / (ll)j * w * ar[ans] >= b) || h * (ll)j >= b && (ok || pref[ans] / (ll)j * w * ar[ans] >= a)) return ans + 1;

            }
    }
    return INF;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    fr(i, n)
        cin >> ar[i];
    sort(ar, ar + n);
    reverse(ar, ar + n);
    pref[0] = 1;
    int len = min(n, (ll)36);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] * ar[i];
//        if (pref[i + 1] > 10000000000ll) {
//            len = min(n, (ll)i + 2);
//            break;
//        }
    }
    //cout << len << endl;
    //ll ans = min(solve(h, w, a, b, len), solve(h, w, b, a, len));
    ll ans = solve(h, w, a, b, len);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}