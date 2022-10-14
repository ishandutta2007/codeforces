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
#define MAXN 100000
#define LogN 17

vector <int> nums[MAXN];
int depth[MAXN], vertex[MAXN][LogN], in[MAXN], out[MAXN], t = 0;

int dfs(int n, int pa) {
    depth[n] = ~pa ? depth[pa] + 1 : 0;
    in[n] = t++;
    vertex[n][0] = pa;
    fop (i,1,LogN) {
        int k = vertex[n][i-1];
        if (k == -1) break;
        vertex[n][i] = vertex[k][i-1];
    }
    for (int i : nums[n]) {
        if (i == pa) continue;
        dfs(i, n);
    }
    out[n] = t++;
}

int lca(int a, int b) {
    if (in[a] <= in[b] and out[a] >= out[b]) return a;
    if (in[b] <= in[a] and out[b] >= out[a]) return b;
    FOP (i,LogN,0) {
        int k = vertex[a][i];
        if (k == -1) continue;
        if (!(in[k] <= in[b] and out[k] >= out[b])) a = k;
    }
    return vertex[a][0];
}

int find_length(int a, int b) {
    int k = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[k];
}

void calc() {
    fop (i,0,MAXN) {
        fop (j,0,LogN) {
            vertex[i][j] = -1;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    calc();
    int n, a, b;
    cin >> n;
    fop (i,0,n-1) {
        cin >> a >> b;
        a--, b--;
        nums[a].pb(b);
        nums[b].pb(a);
    }
    dfs(0, -1);
    int q, x, y, k;
    cin >> q;
    while (q--) {
        cin >> x >> y >> a >> b >> k;
        bool is = false;
        x--, y--, a--, b--;
        // 1 3 1 2
        int a1 = find_length(a, b);
        if (a1 <= k and !((k - a1) & 1)) is = true;
        int a2 = find_length(a, x) + find_length(y, b) + 1;
        if (a2 <= k and !((k - a2) & 1)) is = true;
        int a3 = find_length(a, y) + find_length(x, b) + 1;
        if (a3 <= k and !((k - a3) & 1)) is = true;
        if (is) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}