#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

const int N = 5000;
vector <int> adj[N];
vector <bool> ans(N, false);

int dfs(int v, int pa) {
    int sz = 1;
    vector <int> aa;
    for (int u : adj[v]) if (u != pa) {
        int tmp = dfs(u, v);
        if (pa == -1) aa.pb(tmp);
        sz += tmp;
    }
    if (pa == -1) {
        vector <bool> aaa(N, false);
        fop (i,0,aa.size()) {
            vector <int> tmp;
            fop (j,0,N) {
                if (aaa[j] and aa[i] + j < N) {
                    tmp.pb(aa[i] + j);
                }
            }
            for (int i : tmp) aaa[i] = true;
            aaa[aa[i]] = true;
        }
        fop (i,0,N) if (aaa[i]) {
            ans[i] = true;
        }
    }
    return sz;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n-1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fop (i,0,n) dfs(i, -1);
    int k = 0;
    fop (i,1,n - 1) if (ans[i]) ans[n - 1 - i] = true;
    fop (i,1,n - 1) if (ans[i]) k++;
    cout << k << endl;
    fop (i,1,n - 1) {
        if (ans[i]) cout << i << ' ' << n - 1 - i << endl;
    }
}