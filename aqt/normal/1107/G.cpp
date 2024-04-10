#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dif[300005], v[300005];
long long ans = 0;
long long tbl[300005][20][3];

void rec(int l, int r){
    if(r-l < 1){
        return;
    }
    int k = 31 - __builtin_clz(r-l);
    int idx = (dif[tbl[l][k][0]] > dif[tbl[r-1-(1<<k)+1][k][0]] ?
                tbl[l][k][0] : tbl[r-1-(1<<k)+1][k][0]);
    k = 31 - __builtin_clz(r-idx);
    long long rht = max(tbl[idx][k][1], tbl[r-(1<<k)+1][k][1]);
    k = 31 - __builtin_clz(idx-1-l+1);
    long long lft = min(tbl[l-1][k][2], tbl[idx-1-(1<<k)+1][k][2]);
    ans = max(ans, rht - lft - dif[idx]);
    rec(l, idx);
    rec(idx+1, r);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> dif[i] >> v[i];
        v[i] -= K;
        v[i] *= -1;
        ans = max(ans, v[i]);
        v[i] += v[i-1];
        tbl[i][0][0] = i;
        tbl[i][0][1] = tbl[i][0][2] = v[i];
    }
    for(int i = 1; i<=N; i++){
        dif[i] = (dif[i+1] - dif[i]) * (dif[i+1] - dif[i]);
    }
    for(int d = 1; d<20; d++){
        for(int i = 1; i<N-(1<<d)+1; i++){
            tbl[i][d][0] = dif[tbl[i][d-1][0]] > dif[tbl[i+(1<<(d-1))][d-1][0]] ?
                            tbl[i][d-1][0] : tbl[i+(1<<(d-1))][d-1][0];
        }
        for(int i = 0; i<=N-(1<<d)+1; i++){
            tbl[i][d][1] = max(tbl[i][d-1][1], tbl[i+(1<<(d-1))][d-1][1]);
            tbl[i][d][2] = min(tbl[i][d-1][2], tbl[i+(1<<(d-1))][d-1][2]);
        }
    }
    rec(1, N);
    cout << ans << endl;
}