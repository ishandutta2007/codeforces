#include<bits/stdc++.h>
// #include<atcoder/segtree>
using namespace std;
// using namespace atcoder;
vector<vector<pair<int, int>>> edges;
vector<vector<long long>> cnt;
vector<vector<long long>> mi;
vector<int> tot;
long long ans = 0;
const int N = 500500;
int ind = 0;

void dfs(int pos, int bpos){
    for(auto tmp: edges[pos]){
        int npos = tmp.first;
        if(npos == bpos) continue;
        int c = tmp.second;
        cnt[c].push_back(0);
        mi[c].push_back(0);
        int bind = ind;
        ind++;
        dfs(npos, pos);
        long long cc = (ind - bind) - mi[c].back();
        tot[c] += cc;
        ans += cc * cnt[c].back();
        cnt[c].pop_back();
        cnt[c][cnt[c].size() - 1] += cc;
        mi[c][mi[c].size() - 2] += mi[c][mi[c].size() - 1] + cc;
        mi[c].pop_back();
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    edges.resize(n);
    cnt.resize(n);
    mi.resize(n);
    tot.resize(n);
    int u, v, x;
    set<int> color;
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d %d", &u, &v, &x);
        u--; v--; x--;
        edges[u].push_back({v, x});
        edges[v].push_back({u, x});
        color.insert(x);
    }
    ans = 0;
    for(int i = 0; i < n; i++){
        if(color.count(i)){
            tot[i] = 0;
            cnt[i].push_back(0);
            mi[i].push_back(0);
        }
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++){
        if(color.count(i)){
            ans += (long long)(n - tot[i]) * cnt[i][0];
        }
    }
    cout << ans << "\n";

}

int main(){
	solve();
}