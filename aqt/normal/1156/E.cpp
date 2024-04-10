#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int pos[200005];
int tbl[200005][20];
int ans = 0;

void rec(int l, int r){
    if(r - l <= 0){
        return;
    }
    int k = 31 - __builtin_clz((r-l+1));
    int v = max(tbl[l][k], tbl[r-(1<<k)+1][k]);
    int p = pos[v];
    if(p-l > r-p){
        for(int i = p+1; i<=r; i++){
            if(pos[v-arr[i]] < p && pos[v-arr[i]] >= l){
                ans++;
            }
        }
    }
    else{
        for(int i = p-1; i>=l; i--){
            if(pos[v-arr[i]] > p && pos[v-arr[i]] <= r){
                ans++;
            }
        }
    }
    rec(l, p-1);
    rec(p+1, r);
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
        tbl[i][0] = arr[i];
    }
    for(int d = 1; d<20; d++){
        for(int i = 1; i<=N-(1<<d)+1; i++){
            tbl[i][d] = max(tbl[i][d-1], tbl[i+(1<<(d-1))][d-1]);
        }
    }
    rec(1, N);
    cout << ans << endl;
}