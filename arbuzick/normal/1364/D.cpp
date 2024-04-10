#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int maxn = 100000;
vector<int> g[maxn];
int used[maxn], used2[maxn];
vector<int> ans[2];
void dfs2(int v, int c){
    used2[v] = 3-c;
    ans[used2[v]-1].pb(v);
    for(auto u: g[v])
        if(!used2[u])
            dfs2(u, used2[v]);
}
int n, m, k;
vector<int> path;
bool f = 0;
void dfs(int v, int pr){
    used[v] = 1;
    path.pb(v);
    for(auto u: g[v]){
        if(!f && used[u] == 1 && u != pr){
            int ind = 0;
            for(int i = 0; i < path.size(); ++i)
                if(u == path[i])
                    ind  = i;
            vector<int> path1;
            for(int i = ind; i < path.size(); ++i)
                path1.pb(path[i]);
            path = path1;
            f = 1;
        }
        if(!f && used[u] == 0)
            dfs(u, v);
    }
    used[v] = 2;
    if(!f)
        path.pop_back();
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    if(!f){
        dfs2(0, 2);
        cout << 1 << '\n';
        if(ans[0].size() >= (k+1)/2){
            for(int i = 0; i < (k+1)/2; ++i)
                cout << ans[0][i]+1 << ' ';
        }else{
            for(int i = 0; i < (k+1)/2; ++i)
                cout << ans[1][i]+1 << ' ';
        }
        return 0;
    }
    vector<int> ind(n, -1);
    for(int i = 0; i < path.size(); ++i)
        ind[path[i]] = i;
    vector<int> path2;
    for(int i = path[0]; i != -1;){
        path2.pb(i);
        int j = ind[i]+1;
        for(auto u: g[i])
            if(ind[i] != 0 || ind[u]+1 != path.size())
                j = max(j, ind[u]);
        if(j == path.size())
            i = -1;
        else
            i = path[j];
    }
    if(path2.size() <= k){
        cout << 2 << '\n';
        cout << path2.size() << '\n';
        for(int i = 0; i < path2.size(); ++i)
            cout << path2[i]+1 << ' ';
    }else{
        cout << 1 << '\n';
        for(int i = 0; i < k+k%2; i += 2)
            cout << path2[i]+1 << ' ';
    }
	return 0;
}