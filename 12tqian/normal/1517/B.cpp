#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF = 1e18;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vl> b(n, vl(m));
        f0r(i, n) {
            f0r(j, m) {
                cin >> b[i][j];
            }
        } 
        ll ans = 0;
        vector<vi> res(n, vi(m));
        f0r(runner, m) { 
            array<ll, 3> best = {INF, INF, INF};
            f0r(i, n) {
                f0r(j, m) {
                    ckmin(best, {b[i][j], i, j});
                }
            }
            ans += best[0];
            int x = best[1];
            int y = best[2];
            f0r(i, n) {
                if (i == x) {
                    res[i][runner] = b[x][y];
                    b[x][y] = INF;
                    continue;
                }
                array<ll, 3> mx = {0, 0, 0};
                f0r(j, m) {
                    if (b[i][j] == INF) continue;
                    ckmax(mx, {b[i][j], i, j});
                }
                res[mx[1]][runner] = mx[0];
                b[mx[1]][mx[2]] = INF;
            }

        }
        f0r(i, n) {
            f0r(j, m) {
                cout << res[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}