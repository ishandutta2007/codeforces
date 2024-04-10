#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 1e9+7;
long long arr[100005];
vector<int> graph[100005];
vector<pair<long long, int>> lst[100005];
long long ans = 0;

long long mult(long long a, long long b){
    return (a%MOD*b%MOD)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

void dfs(int n, int p){
    ans = add(ans, arr[n]);
    lst[n].push_back({arr[n], 1});
    for(auto pr : lst[p]){
        long long G = __gcd(pr.first, arr[n]);
        ans = add(ans, mult(G, pr.second));
        if(lst[n].back().first == G){
            lst[n].back().second += pr.second;
        }
        else{
            lst[n].push_back({G, pr.second});
        }
    }
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
}