#include <bits/stdc++.h>

using namespace std;

int N;
int nxt[200005];
long long pow2[200005], MOD = 1e9+7;
vector<int> sz;
int dist[200005];
int typ[200005];

void dfs(int n){
    typ[n] = 1;
    if(typ[nxt[n]] == 1){
        sz.push_back(dist[n]-dist[nxt[n]]+1);
    }
    else if(!typ[nxt[n]]){
        dist[nxt[n]] = dist[n] + 1;
        dfs(nxt[n]);
    }
    typ[n] = 2;
}

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> nxt[i];
    }
    for(int i = 1; i<=N; i++){
        if(!typ[i]){
            dfs(i);
        }
    }
    pow2[0] = 1;
    for(int i =1; i<=N; i++){
        pow2[i] = (pow2[i-1]*2)%MOD;
    }
    long long ans = 1;
    for(int k : sz){
        ans = ans*(pow2[k]-2)%MOD;
        N-= k;
    }
    ans = (ans*pow2[N])%MOD;
    cout << ans << endl;
}