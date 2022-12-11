#include <bits/stdc++.h>

using namespace std;

int N;
int ans[200005];
vector<int> graph[200005];
int arr[200005];
int cnt[200005];
int dep[200005];

void upd(int n, int v){
    for(int k = 1; k<=sqrt(arr[n]); k++){
        if(arr[n]%k == 0){
            cnt[k] += v;
            if(arr[n]/k != k){
                cnt[arr[n]/k] += v;
            }
        }
    }
}

void dfs1(int n, int p){
    upd(n, 1);
    for(int k = 1; k<=sqrt(arr[1]); k++){
        if(arr[1]%k == 0){
            if(cnt[k] >= dep[n] - 1){
                ans[n] = max(ans[n], k);
            }
            if(cnt[arr[1]/k] >= dep[n] - 1){
                ans[n] = max(ans[n], arr[1]/k);
            }
        }
    }
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        dep[e] = dep[n] + 1;
        dfs1(e, n);
    }
    upd(n, -1);
}

void dfs2(int n, int p, int v){
    v = __gcd(arr[n], v);
    ans[n] = max(ans[n], v);
    for(int e : graph[n]){
        if(e != p){
            dfs2(e, n, v);
        }
    }
}

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dep[1] = 1;
    dfs1(1, 0);
    for(int e : graph[1]){
        dfs2(e, 1, 0);
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}