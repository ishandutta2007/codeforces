#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

bool mark[maxn], mark2[maxn];
vector<int> v[maxn];
int n, m;

void to_graph(vector<pii> ed){
    for(int i = 0; i <= n; i++)
        v[i].clear();
    for(int i = 0; i <= n; i++)
        mark[i] = mark2[i] = false;
    for(pii p : ed){
        v[p.first].push_back(p.second);
        v[p.second].push_back(p.first);
    }
}

int h[maxn], bsth[maxn];

void dfs_cut(int u, int par, vector<pii> &ret){
    // h not initailized!
    mark[u] = 1;
    bsth[u] = h[u];
    for(int y : v[u]){
        if(!mark[y]){
            h[y] = h[u] + 1;
            dfs_cut(y, u, ret);
            bsth[u] = min(bsth[u], bsth[y]);
        }
        else if(y != par){
            bsth[u] = min(bsth[u], h[y]);
        }
    }
    if(par != -1 && bsth[u] == h[u]){
        ret.push_back({u, par});
    }
}
vector<pii> get_cut_edges(vector<pii> ed){
    to_graph(ed);
    vector<pii> ans;
    for(int i = 1; i <= n; i++){
        if(mark[i] == false)
            dfs_cut(i, -1, ans);
    }
    return ans;
}

void dfs_match(int u, vector<pii> &ret){
    mark[u] = 1;
    for(int y : v[u]){
        if(!mark[y]){
            dfs_match(y, ret);
            bool matched = false;
            if(!mark2[u] && !mark2[y] && (v[u].size()&1) && (v[y].size()&1)){
                mark2[u] = mark2[y] = true;
                matched = true;
            }
            if(!matched){
                ret.push_back({u, y});
            }
        }
    }
}

vector<pii> get_not_matching_edges(vector<pii> ed){
    to_graph(ed);
    vector<pii> ans;
    for(int i = 1; i <= n; i++){
        if(mark[i] == false)
            dfs_match(i, ans);
    }
    return ans;
}

int dfs_partition(int u, vector<pii> &ret){
    mark[u] = 1;
    int lst = u;
    for(int y : v[u]){
        if(!mark[y]){
            int w = dfs_partition(y, ret);
            if(lst == u){
                lst = w;
            }
            else{
                ret.push_back({lst, w});
                lst = u;
            }
        }
    }
    return lst;
}

vector<pii> get_partition(vector<pii> ed){
    to_graph(ed);
    vector<pii> ans;
    for(int i = 1; i <= n; i++){
        if(mark[i] == false){
            int x = dfs_partition(i, ans);
            if(x != i)
                ans.push_back({x, i});
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    while(cin >> n >> m){
        if(n == 0 && m == 0)
            return 0;
        vector<pii> ed;
        while(m--){
            int s;
            cin >> s;
            int bef;
            cin >> bef;
            for(int i = 0; i < s-1; i++){
                int nw;
                cin >> nw;
                ed.push_back({bef, nw});
                bef = nw;
            }
        }
        ed = get_cut_edges(ed);
        ed = get_not_matching_edges(ed);
        ed = get_partition(ed);
        cout << ed.size() << "\n";
        for(pii p : ed){
            cout << p.first << " " << p.second << "\n";
        }
    }   
    return 0;
}