#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 100;
const int M = 1e3 + 10;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int cnt[N];
vector <int> g[N];
vector <vector <int> > g2;

bool cmp(int a, int b) {
    if (g2[a].size() != g2[b].size())
        return g2[a].size() < g2[b].size();
    fr(i, g2[a].size())
        if (g2[a][i] != g2[b][i])
            return g2[a][i] < g2[b][i];
    return a < b;
}

ll fac[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fac[0] = fac[1] = 1;
    frab(i, 2, max(n, m) + 2)
        fac[i] = (fac[i - 1] * (ll)i) % MOD;
    g2.resize(m);
    fr(i, n) {
        cin >> cnt[i];
        fr(j, cnt[i]) {
            int x;
            cin >> x;
            x--;
            g[i].pb(x);
        }
        //sort(g[i].begin(), g[i].end());
    }

    fr(i, n)
        fr(j, cnt[i])
            g2[g[i][j]].pb(i);

    vector <int> ind;
    fr(i, m)
        ind.pb(i);
    sort(ind.begin(), ind.end(), cmp);

//    fr(i, m) {
//        fr(j, g2[i].size())
//            cout << g2[ind[i]][j] << " ";cout << endl;}
//    fr(i, ind.size())
//        cout << ind[i] << " ";cout << endl;
    ll ans = 1;
    fr(i, m) {
        int cur = 1;
        while (i + 1 < m && g2[ind[i]] == g2[ind[i + 1]])
            cur++, i++;
        ans = (ans * fac[cur]) % MOD;
    }
    cout << ans << endl;
}