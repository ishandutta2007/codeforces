#include <bits/stdc++.h>

using namespace std;

int N, Q;
int dist[1000005];
bool tkn[1000005];
int par[1000005];
vector<int> graph[1000005];

void dfs(int n, int p){
    for(int e : graph[n]){
        if(e != p){
            par[e] = n;
            dist[e] = min(e, dist[n]);
            dfs(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    Q--;
    int c, rt;
    cin >> c >> rt;
    rt = rt%N+1;
    dist[rt] = rt;
    dfs(rt, 0);
    int glo = rt;
    tkn[rt] = 1;
    int lst = 0;
    while(Q--){
        int x;
        cin >> c >> x;
        x = (x+lst)%N+1;
        if(c == 1){
            while(!tkn[x]){
                tkn[x] = 1;
                glo = min(glo, x);
                x = par[x];
            }
        }
        else{
            lst = min(glo, dist[x]);
            cout << lst << "\n";
        }
    }
}