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
#define MID 350

int main () {
    int n,m,k,u,v,w,now = 0;
    cin >> n >> m >> k;
    pair <int, pii> edge[m];
    fop (i,0,m) {
        cin >> u >> v >> w;
        u--; v--;
        edge[i] = {w, {u, v}};
    }
    sort(edge, edge + m);
    vector <int> new_order(n, -1);
    lli path[1000][1000];
    fop (i,0,1000) fop (j,0,1000) path[i][j] = 1ll << 60;
    fop (i,0,min(k,m)) {
        w = edge[i].X;
        tie(u, v) = edge[i].Y;
        if (new_order[u] == -1) new_order[u] = now++;
        if (new_order[v] == -1) new_order[v] = now++;
        path[new_order[u]][new_order[v]] = min(path[new_order[u]][new_order[v]], 1ll * w);
        path[new_order[v]][new_order[u]] = min(path[new_order[v]][new_order[u]], 1ll * w);
    }
    fop (l,0,now) {
        fop (i,0,now) {
            fop (j,0,now) {
                if (i == j) continue;
                path[i][j] = min(path[i][j], path[i][l] + path[l][j]);
            }
        }
    }
    vector <lli> new_edge;
    fop (i,0,now) {
        fop (j,i+1,now) {
            new_edge.push_back(path[i][j]);
        }
    }
    sort(new_edge.begin(), new_edge.end());
    cout << new_edge[k-1] << '\n';
}