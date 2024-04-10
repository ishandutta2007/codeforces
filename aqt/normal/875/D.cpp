#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int pre[200005][32];
int tbl[200005][32];

int hbit(int v){
    for(int i = 30; i>=0; i--){
        if(v&(1<<i)){
            return i;
        }
    }
    return -1;
}

long long rec(int l, int r){
    if(r<l){
        return 0;
    }
    int lst = hbit(r-l+1);
    int idx = arr[tbl[l][lst]] > arr[tbl[r-(1<<lst)+1][lst]] ? tbl[l][lst] : tbl[r-(1<<lst)+1][lst];
    int lft = l, rht = idx, lb = idx;
    while(lft <= rht){
        int mid = (lft+rht)>>1;
        bool b = 0;
        for(int i = 0; i<30; i++){
            if((1<<i)&arr[idx]){
                continue;
            }
            b |= pre[idx][i] - pre[mid-1][i];
        }
        if(b){
            lft = mid + 1;
        }
        else{
            lb = mid;
            rht = mid - 1;
        }
    }
    lft = idx;
    rht = r;
    int ub = idx;
    while(lft <= rht){
        int mid = (lft+rht)>>1;
        bool b = 0;
        for(int i = 0; i<30; i++){
            if((1<<i)&arr[idx]){
                continue;
            }
            b |= pre[mid][i] - pre[idx-1][i];
        }
        if(b){
            rht = mid - 1;
        }
        else{
            ub = mid;
            lft = mid + 1;
        }
    }
    return 1LL*(idx-lb+1)*(ub-idx+1) + rec(l, idx-1) + rec(idx+1, r);
}

int main(){
    scanf("%d", &N);
    for(int i =1 ; i<=N; i++){
        scanf("%d", &arr[i]);
        for(int j = 0; j<30; j++){
            if((1<<j)&arr[i]){
                pre[i][j]++;
            }
            pre[i][j] += pre[i-1][j];
        }
        tbl[i][0] = i;
    }
    for(int h = 1; h<=20; h++){
        for(int i = 1; i<=N-(1<<h)+1; i++){
            tbl[i][h] =
                arr[tbl[i][h-1]] > arr[tbl[i+(1<<(h-1))][h-1]] ? tbl[i][h-1] : tbl[i+(1<<(h-1))][h-1];
        }
    }
    cout << 1LL*(N)*(N+1)/2 - rec(1, N);
}