#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 5e5 + 10;

vector <int> g[N], tg[N];
int ans[N];
int step[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        step[v]++;
        tg[u].pb(v);
    }

    set <pair <int, int> > s;
    fr(i, n)
        s.insert(mp(step[i], -i));

    fr(i, n) {
        auto t1 = s.begin();
        int v = -t1->second;
        ans[v] = n - i;
        for (auto u: tg[v]) {
            auto x = mp(step[u], -u);
            s.erase(x);
            step[u]--;
            s.insert(mp(step[u], -u));
        }
        s.erase(t1);
    }

    fr(i, n)
        cout << ans[i] << " ";

}