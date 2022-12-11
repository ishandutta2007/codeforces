#include <bits/stdc++.h>

using namespace std;

int N;
int par[200005], big[200005];
vector<int> graph[200005];
int mn[200005], mx[200005];
int val[200005];
int cnt;
pair<int, int> edge[200005];
vector<int> ans;

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dfs(int n, int p){
    mn[n] = INT_MAX;
    if(graph[n].size() == 1 && n-1){
        mx[n] = mn[n] = ++cnt;
        par[cnt] = cnt;
        return;
    }
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
            mn[n] = min(mn[e], mn[n]);
            mx[n] = max(mx[e], mx[n]);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cnt++;
    par[cnt] = cnt;
    for(int n = 1; n<=N; n++){
        edge[n] = {val[n], n};
    }
    sort(edge+1, edge+1+N);
    long long out = 0;
    for(int i = 1; i<=N; ){
        int cur = i;
        for(; i<=N && edge[i].first == edge[cur].first; i++){
            int n = edge[i].second;
            int a = getrt(mn[n]), b = getrt(mx[n]+1);
            if(a != b){
                ans.push_back(n);
            }
        }
        for(i = cur; i<=N && edge[i].first == edge[cur].first; i++){
            int n = edge[i].second;
            int a = getrt(mn[n]), b = getrt(mx[n]+1);
            if(a != b){
                par[b] = a;
                big[a] = val[n];
                out += val[n];
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << out << " " << ans.size() << "\n";
    for(int n : ans){
        cout << n << " ";
    }
}