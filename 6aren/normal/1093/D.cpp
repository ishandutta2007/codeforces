#include <bits/stdc++.h>
using namespace std;

const int N=300000+5;
const int MOD=998244353;

int ntest, check[N], n, m;
vector <int> nebo[N];

int luythua(int u){
    int res=1;
    for (int i=1; i<=u; i++){
        res=(res*2)%MOD;
    }
    return res;
}

int BFS(int u){
    int cnt[3];
    cnt[1]=1;
    cnt[2]=0;
    queue <int> Q;
    while (!Q.empty()) Q.pop();
    Q.push(u);
    check[u] = 1;
    int ok=0;
    while (!Q.empty()){
        int v=Q.front();
        Q.pop();
        for (int i=0; i<nebo[v].size(); i++){
            int t=nebo[v][i];
            if (!check[t]){
                Q.push(t);
                check[t]=3-check[v];
                cnt[check[t]]++;
            } else if (check[t]==check[v]) {
                ok=1;
            }
        }
    }
    if (ok!=1) return (luythua(cnt[2])+luythua(cnt[1]))%MOD;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ntest;
    while (ntest--){
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            nebo[i].clear();
            check[i]=0;
        }
        for (int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            nebo[u].push_back(v);
            nebo[v].push_back(u);
        }
        long long res=1;
        for (int i=1; i<=n; i++){
            if (!check[i]){
                res=(res*BFS(i))%MOD;
            }
        }
        printf("%ld \n", res);
    }
}