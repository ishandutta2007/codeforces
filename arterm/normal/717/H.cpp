#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef vector<int> vi;

const int maxn = 1000500;

int n, m;
vi hate[maxn];
vi can[maxn];
int T;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        hate[--v].push_back(--u);
        hate[u].push_back(v);
    }
    forn(i, n) {
        int l;
        scanf("%d", &l);
        can[i].resize(l);
        forn(j, l) {
            scanf("%d", &can[i][j]), --can[i][j];
            T = max(T, can[i][j] + 1);
        }
    }
}

int tcol[maxn];
int team[maxn];
int score;

mt19937 rr;

void solve() {
    score = 0;
    while (2 * score < m) {
        score = 0;
        forn(i, T) tcol[i] = rr() % 2;
        forn(i, n) {
            bool can0 = false;
            bool can1 = false;
            for (int x: can[i]) {
                if (tcol[x]) can1 = true;
                else can0 = true;
            }
            int sel = -1;
            int score0 = 0, score1 = 0;
            for (int to: hate[i]) if (to < i) {
                if (tcol[team[to]]) ++score0;
                else ++score1;
            }

            if (!can0) sel = 1;
            else if (!can1) sel = 0;
            else {
                sel = score0 > score1 ? 0 : 1;
            }

            score += sel ? score1 : score0;
            team[i] = -1;
            for (int x: can[i]) if (tcol[x] == sel) {
                team[i] = x;
                break;
            }
            assert(team[i] != -1);
        }
    }
    forn(i, n) printf("%d ", team[i] + 1);
    printf("\n");
    forn(i, T) printf("%d ", tcol[i] + 1);
    printf("\n");
}

int main() {
    #ifdef LOCAL
    assert(freopen("h.in", "r", stdin));
    #else
    #endif

    scan();
    solve();

}