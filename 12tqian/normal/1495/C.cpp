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

const int N = 510;
int g[N][N];
void solve_case() {
    int n, m; cin >> n >> m;
    f0r(i, n) {
        string line; cin >> line;
        f0r(j, m) {
            if (line[j] == 'X') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i += 3) {
        f0r(j, m) g[i][j] = 1;
    }
    for (int i = 0; i < n; i += 3) {
        if (i + 3 >= n) {
            f0r(j, m) {
                if (g[i + 1][j] && i + 1 < n || g[i + 2][j] && i + 2 < n) {
                    g[i + 1][j] = g[i + 2][j] = 1;
                }
            }
            continue;
        }
        vi top, bot;
        f0r(j, m) {
            if (g[i + 1][j] && i + 1 < n) {
                top.pb(j);
            } else if (g[i + 2][j] && i + 2 < n) {
                bot.pb(j);
            }
        }
        if (sz(top) == 0 && sz(bot) == 0) {
            g[i + 1][0] = g[i + 2][0] = 1;
        } else if (sz(top)) {
            g[i + 2][top.back()] = 1;
        } else if (sz(bot)) {
            g[i + 1][bot.back()] = 1;
        }
    }
    f0r(i, n) {
        f0r(j, m) {
            if (g[i][j]) cout << "X";
            else cout << ".";
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << '\n';
#endif
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(15);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}