#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int, int>> graph[100005];
bool vis[100005];
int sz[100005];
vector<pair<int, int>> s;
int dep[100005], dist[100005];
long long ans = 0;
int BIT[200005];
vector<int> cmp;

int getidx(int n){
    return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin() + 1;
}

void upd(int n, int v){
    n = getidx(n);
    while(n <= cmp.size()){
        BIT[n] += v;
        n += n&-n;
    }
}

int query(int n){
    int s = 0;
    n = getidx(n);
    while(n){
        s += BIT[n];
        n -= n&-n;
    }
    return s;
}

void dfs1(int n, int p){
    sz[n] = 1;
    for(auto e : graph[n]){
        if(e.first != p && !vis[e.first]){
            dfs1(e.first, n);
            sz[n] += sz[e.first];
        }
    }
}

int getcent(int n, int p, int tot){
    int hvy = 0;
    for(auto e : graph[n]){
        if(e.first != p && !vis[e.first]){
            hvy = (sz[e.first] > sz[hvy] ? e.first : hvy);
        }
    }
    if(2*sz[hvy] <= tot){
        return n;
    }
    else{
        return getcent(hvy, n, tot);
    }
}

void dfs2(int n, int p){
    s.push_back({dep[n], dist[n]});
    for(auto e : graph[n]){
        if(e.first != p && !vis[e.first]){
            if(dep[n] + 1 <= M && dist[n] + e.second <= K){
                dep[e.first] = dep[n] + 1;
                dist[e.first] = dist[n] + e.second;
                dfs2(e.first, n);
            }
        }
    }
}

void proc(int c){
    sort(s.begin(), s.end());
    for(auto p : s){
        cmp.push_back(p.second);
        cmp.push_back(K-p.second);
    }
    sort(cmp.begin(), cmp.end());
    for(auto p : s){
        upd(p.second, 1);
    }
    int rht = s.size()-1;
    for(int lft = 0; lft<s.size(); lft++){
        while(rht >= 0 && s[lft].first + s[rht].first > M){
            upd(s[rht--].second, -1);
        }
        ans += c*query(K-s[lft].second);
    }
    while(rht >= 0){
        upd(s[rht--].second, -1);
    }
    s.clear();
    cmp.clear();
}

void solve(int n){
    dfs1(n, 0);
    n = getcent(n, 0, sz[n]);
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    vis[n] = 1;
    for(auto e : graph[n]){
        if(!vis[e.first]){
            dep[e.first] = 1;
            dist[e.first] = e.second;
            dfs2(e.first, n);
            for(auto p : s){
                v.push_back(p);
            }
            proc(-1);
        }
    }
    swap(v, s);
    proc(1);
    assert(v.empty());
    for(auto p : graph[n]){
        if(!vis[p.first]){
            solve(p.first);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 2; i<=N; i++){
        int a, b;
        cin >> a >> b;
        graph[i].push_back({a, b});
        graph[a].push_back({i, b});
    }
    ans = -N;
    solve(1);
    cout << ans/2 << "\n";
}