#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const int INF = 1e9;
const int LOG = 30;
const int N = 2e5 + 10;
int mod = 0;

vector<pair<int, int>> g[N];
bool usedCD[N];
int sz[N];

void calcSz(int v, int par) {
    sz[v] = 1;
    for (auto u: g[v])
        if (!usedCD[u.first] && u.first != par) {
            calcSz(u.first, v);
            sz[v] += sz[u.first];
        }
}

ll globalAns = 0;

map<int, int> globUp;
map<pair<int, int>, int> globDown;
map<int, int> chUp[N];
map<pair<int, int>, int> chDown[N];

ll pow10[N];

void dfsSolve(int v, int child, int h, ll upSum, ll downSum, int par) {
    globUp[upSum]++;
    globDown[{downSum, h}]++;
    chUp[child][upSum]++;
    chDown[child][{downSum, h}]++;
    for (auto u: g[v]) {
        if (usedCD[u.first] || u.first == par) continue;
        dfsSolve(u.first, child, h + 1,
                (pow10[h] * u.second + upSum) % mod,
                (downSum * 10 + u.second) % mod, v);
    }
}

ll rev(ll x, ll m) {
    if (x == 1) return 1;
    assert(x > 0);
    return (1 - rev(m % x, x) * m) / x + m;
}

void countAns(int v) {

    globUp.clear();
    globDown.clear();

    globUp[0] = 1;
    globDown[{0, 0}] = 1;

    for (auto u: g[v])
        if (!usedCD[u.first]) {
            chUp[u.first].clear();
            chDown[u.first].clear();
        }

    for (auto u: g[v])
        if (!usedCD[u.first]) {
            dfsSolve(u.first, u.first, 1, u.second % mod, u.second % mod, v);
        }

    for (auto t: globDown) {
        int r2 = t.first.first;
        int h = t.first.second;
        int cnt = t.second;

        int r1 = 0;
        if (mod != 1)
            r1 = (ll)(mod - r2) * rev(pow10[h], mod) % mod;
        if (globUp.count(r1)) {
            globalAns += (ll)globUp[r1] * cnt;
        }
    }

    for (auto u: g[v]) {
        if (usedCD[u.first]) continue;
        for (auto t: chDown[u.first]) {
            int r2 = t.first.first;
            int h = t.first.second;
            int cnt = t.second;

            int r1 = 0;
            if (mod != 1)
                r1 = (ll)(mod - r2) * rev(pow10[h], mod) % mod;
            if (chUp[u.first].count(r1)) {
                globalAns -= (ll)chUp[u.first][r1] * cnt;
            }
        }
    }
    globalAns--;
}

void dfs(int v, int siz, int par) {
    bool fnd = false;
    for (auto u: g[v]) {
        if (!usedCD[u.first] && u.first != par && sz[u.first] >= (siz + 1) / 2) {
            fnd = true;
            dfs(u.first, siz, v);
            break;
        }
    }

    if (!fnd) {
        usedCD[v] = true;
//        int tmpG = globalAns;
        countAns(v);
//        for (auto t: globDown)
//            cout << t.first.first << " " << t.first.second << " " << t.second << endl;
//        cout << "v: " << v << " " << globalAns - tmpG << endl;
        for (auto u: g[v]) {
            if (!usedCD[u.first]) {
                calcSz(u.first, v);
                dfs(u.first, sz[u.first], v);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n >> mod;

    pow10[0] = 1;
    for (int i = 1; i <= n; i++)
        pow10[i] = pow10[i - 1] * 10 % mod;

    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].pb({u, w});
        g[u].pb({v, w});
    }

    calcSz(0, -1);
    dfs(0, n, -1);

    cout << globalAns << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}