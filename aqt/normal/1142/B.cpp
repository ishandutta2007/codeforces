#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int perm[400005], pos[200005];
int arr[400005];
vector<int> graph[400005];
int tbl[20][400005];
int lst[400005];
int dep[400005];
int pth[400005];

void dfs(int n){
    //cout << n << endl;
    pth[dep[n]] = n;
    if(dep[n] >= N){
        tbl[0][n] = pth[dep[n]-N+1];
    }
    for(int e : graph[n]){
        dep[e] = dep[n] + 1;
        dfs(e);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    for(int i = 0; i<N; i++){
        cin >> perm[i];
        pos[perm[i]] = i;
    }
    for(int i = 1; i<=M; i++){
        cin >> arr[i];
        graph[lst[perm[(pos[arr[i]]-1+N)%N]]].push_back(i);
        lst[arr[i]] = i;
    }
    dfs(0);
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=M-(1<<d)+1; n++){
            tbl[d][n] = max(tbl[d-1][n], tbl[d-1][n+(1<<(d-1))]);
        }
    }
    while(Q--){
        int l, r;
        cin >> l >> r;
        int k = 31-__builtin_clz(r-l+1);
        int ans;
        //cout << "here: " << k << " " << max(tbl[k][l], tbl[k][r-(1<<k)+1]) << endl;
        if(max(tbl[k][l], tbl[k][r-(1<<k)+1]) >= l){
            ans = 1;
        }
        else{
            ans =0 ;
        }
        cout << ans;
    }
}