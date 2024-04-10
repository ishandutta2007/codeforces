#include <bits/stdc++.h>
using namespace std;

const int maxn = 1007;
using pii = pair<int,int>;

set<pii> edges;
vector<int> G[maxn];
set<pii> selected_edges;

int used[maxn];
int realans;

void dfs(int now,int p,int m) {
    used[now]=1;
    if (p!=-1 && ((int)selected_edges.size()) < m) {
        selected_edges.insert({min(p,now),max(p,now)});
    }
    for (int i:G[now]) {
        if (i==p) continue;
        dfs(i,now,m);
    }
}

void generate(int n,int m) {
    selected_edges.clear();
    memset(used,0,sizeof(used));
    for (int i=1;i<=n;i++) G[i].clear();
    for (pii i:edges) {
        G[i.first].push_back(i.second);
        G[i.second].push_back(i.first);
    }
    for (int i=1;i<=n;i++) {
        if (!used[i]) {
            used[i]=1;
            dfs(i,-1,m);
        }
    }
}

void query() {
    set<int> ss;

    for (pii i:selected_edges) {
        ss.insert(i.first);
        ss.insert(i.second);
    }
    cout<<"?";
    cout<<' '<<(int)ss.size();
    for (int i:ss) cout<<' '<<i;
    cout<<endl;

    int x; cin>>x;
    if (x==realans) {
        edges=selected_edges;
    } else {
        for (pii i:selected_edges) edges.erase(i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n-1;i++) {
        int u,v; cin>>u>>v;
        edges.insert({min(u,v),max(u,v)});
    }

    cout<<"? "<< n;
    for (int i=1;i<=n;i++) cout<<' '<<i;
    cout<<endl;
    cin>>realans;

    while (int(edges.size()) > 1) {
        int m = (int(edges.size()))/2;
        generate(n,m);
        query();
    }
    cout<<"! "<<(*edges.begin()).first<<' '<<(*edges.begin()).second<<endl;
}