#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[505];
long long dp[505][505];
long long MOD = 998244353;

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long solve(int l, int r){
    //cout << l << " " << r << endl;
    if(r - l <= 0){
        return 1;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int idx = l, val = arr[l];
    for(int i = l; i<=r; i++){
        if(val > arr[i]){
            idx = i;
            val = arr[i];
        }
    }
    //cout << l << " " << r << " " << idx << endl;
    long long lft = 0, rht = 0;
    for(int i = l; i<=idx; i++){
        lft = add(lft, mult(solve(l, i-1), solve(i, idx-1)));
    }
    for(int i = idx; i<=r; i++){
        rht = add(rht, mult(solve(idx+1, i), solve(i+1, r)));
    }
    dp[l][r] = mult(lft, rht);
    return dp[l][r];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    for(int i =0 ; i<=N; i++){
        for(int j = 0; j<=N; j++){
            dp[i][j] = -1;
        }
    }
    cout << solve(1, N);
}