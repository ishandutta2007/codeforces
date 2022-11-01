#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 10;
const ll INF = 2e9;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

vector <int> g[N];
vector <int> langs[N];
bool used[N];
bool nul[N];

void dfs(int v) {
    used[v] = true;
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}


int main() {

        //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, m;
    int was = -1;
    int cnt = 0;
    cin >> n >> m;
    fr(i, n) {
        int q, l;
        cin >> q;
        if (!q)
            nul[i] = true;
        fr(j, q) {
            cin >> l;
            langs[i].pb(l);
            was = l;
        }
    }
    if (was == -1) {
        cout << n;
        return 0;
    }
    fr(i, n)
        if (nul[i]) {
            langs[i].pb(was);
            cnt++;
        }

    fr(i, n)
        sort(langs[i].begin(), langs[i].end());
    fr(i, n)
        fr(j, n) {
            vector <int> x(langs[i].size());
            if (set_intersection(langs[i].begin(), langs[i].end(), langs[j].begin(), langs[j].end(), x.begin()) - x.begin())
                g[i].pb(j);
        }
    fr(i, n)
        if (!used[i]) {
            cnt++;
            dfs(i);
        }
    cout << cnt - 1;
}