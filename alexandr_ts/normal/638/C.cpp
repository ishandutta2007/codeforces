#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

vector <pair <int, int> > g[N];
bool used[N];
int color[N];

vector <int> ans[N];

void dfs(int v, int last) {
    used[v] = true;
    int cur = 0;
    fr(i, (int)g[v].size())
        if (!used[g[v][i].first]) {
            cur++;
            if (cur == last)
                cur++;
            color[g[v][i].second] = cur;
            dfs(g[v][i].first, cur);
        }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(mp(--u, i));
        g[u].pb(mp(v, i));
    }
    dfs(0, INF);
    int answ = 0;
    fr(i, n) {
        answ = max(answ, color[i]);
        ans[color[i]].pb(i);
    }
    cout << answ << endl;
    frab(i, 1, answ + 1) {
        cout << ans[i].size() << " ";
        fr(j, ans[i].size())
            cout << ans[i][j] + 1 << " ";
        cout << endl;
    }

}