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
const int N = 1e6 + 10;

vector <int> g[N];
int mn[N];

void dfs1(int v, int val) {
    mn[v] = val;
    for (auto t: g[v])
        if (!mn[t])
            dfs1(t, min(val, t));
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, q;
    int totMin = N;
    scanf("%d %d", &n, &q);
    fr(i, n - 1) {
        int v, u;
        scanf("%d %d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }

    int last = 0;

    fr(i1, q) {
        int t, z;
        scanf("%d %d", &t, &z);
        int x = (z + last) % n + 1;
        if (t == 1) {
            if (!i1) {
                dfs1(x, x);
            }
            else {
                totMin = min(totMin, mn[x]);
            }
        }
        else {
            last = min(mn[x], totMin);
            cout << last << "\n";
            //printf("%d\n", last);// << last << endl;
        }
    }


}