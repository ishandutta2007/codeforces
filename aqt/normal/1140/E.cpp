#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200010];
long long MOD = 998244353;
long long dp1[200005][2], dp2[200005][2];

long long mult(long long a, long long b){
    return (a%MOD*b%MOD)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long solve(int s){
    int idx = s;
    long long ret = 1;
    while(arr[idx] == -1){
        idx += 2;
        ret = mult(ret, K-1);
    }
    int lst = idx;
    for(idx += 2; idx<=N; idx+=2){
        if(arr[idx] != -1){
            int d = (idx-lst)/2-1;
            if(arr[idx] == arr[lst]){
                ret = mult(ret, dp2[d][0]);
            }
            else{
                ret = mult(ret, dp1[d][0]);
            }
            lst = idx;
        }
    }
    for(lst += 2; lst <= N; lst+=2){
        ret = mult(ret, K-1);
    }
    return ret;
}

int main(){
    cin >> N >> K;
    bool oddneg1 = 1, evenneg1 = 1;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        if(i%2 == 1 && arr[i] != -1){
            oddneg1 = 0;
        }
        if(i%2 == 0 && arr[i] != -1){
            evenneg1 = 0;
        }
    }
    long long ans = 1;
    dp1[1][0] = K-2;
    dp1[1][1] = 1;
    dp2[1][0] = K-1;
    dp1[0][0] = 1;
    for(int i = 2; i<=N; i++){
        dp1[i][0] = add(mult(dp1[i-1][0], K-2), mult(dp1[i-1][1], K-1));
        dp1[i][1] = dp1[i-1][0];
        dp2[i][0] = add(mult(dp2[i-1][0], K-2), mult(dp2[i-1][1], K-1));
        dp2[i][1] = dp2[i-1][0];
    }
    if(evenneg1){
        ans = mult(ans, K);
        for(int i = 4; i<=N; i+=2){
            ans = mult(ans, K-1);
        }
    }
    else{
        ans = mult(ans, solve(2));
    }
    if(oddneg1){
        ans = mult(ans, K);
        for(int i = 3; i<=N; i+=2){
            ans = mult(ans, K-1);
        }
    }
    else{
        ans = mult(ans, solve(1));
    }
    cout << ans << endl;
}