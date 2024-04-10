#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll const MAXN = 200001;

vector<long> g[MAXN];
vector<long> visited;

ll st[MAXN];
ll si[MAXN];
long dfs(ll node){
    long siz = 1;
    st[node] = visited.size();
    visited.push_back(node);
    for(int i = 0;i<g[node].size();i++){
        siz += dfs(g[node][i]);
    }
    si[node] = siz;
    return siz;
}

int main(){
    ll n,q,a;
    cin >> n >> q;
    for(int i = 0;i<n-1;i++){
        cin >> a;
        g[a-1].push_back(i+1);
    }

    dfs(0);
    ll u,k;
    for(int i = 0;i<q;i++){
        cin >> u >> k;
        if(k > si[u-1]){
            cout << -1 << endl;
        }else {
            cout << visited[st[u-1] +k - 1]+1 << endl;
        }
    }
    return 0;
}