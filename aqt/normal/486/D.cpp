#include <bits/stdc++.h>

using namespace std;

int D, N;
int arr[2005];
vector<int> graph[2005];
long long MOD = 1e9+7;
long long ans = 0;

long long dfs(int n, int p, int s){
    long long sz = 1;
    for(int e : graph[n]){
        if(e != p && ((arr[e] > arr[s] && arr[e]-arr[s] <= D)||(arr[e] == arr[s] && e > s))){
            sz += sz*dfs(e, n, s);
            sz %= MOD;
        }
    }
    return sz;
}

void solve(int n){
    long long cur = 1;
    ans++;
    ans %= MOD;
    for(int e : graph[n]){
        if((arr[e] > arr[n] && arr[e]-arr[n] <= D)||(arr[e] == arr[n] && e > n)){
            long long k = dfs(e, n, n);
            ans += (cur*k)%MOD;
            cur += (cur*k)%MOD;
            cur %= MOD;
            ans %= MOD;
        }
    }
}

int main(){
    cin >> D >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i<=N; i++){
        solve(i);
    }
    cout << ans << endl;
}