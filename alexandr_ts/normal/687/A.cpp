#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

vector <int> g[N];
int col[N];
bool ans;

void dfs(int v, int c) {
    col[v] = c;
    fr(i, g[v].size()) {
        if (col[g[v][i]] == c)
            ans = false;
        if (!col[g[v][i]])
            dfs(g[v][i], c % 2 + 1);
    }
}

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    int n, m;
    ans = true;
    cin >> n >> m;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    fr(i, n)
        if (!col[i])
            dfs(i, 1);
    if (!ans) {
        cout << -1;
        return 0;
    }
    vector <int> a1, a2;
    fr(i, n)
        if (col[i] == 1)
            a1.pb(i + 1);
        else
            a2.pb(i + 1);
    cout << a1.size() << endl;
    fr(i, a1.size())
        cout << a1[i] << " ";
    cout << endl << a2.size() << endl;
    fr(i, a2.size())
        cout << a2[i] << " " ;
}