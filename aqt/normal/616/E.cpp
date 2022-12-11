#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;
long long inv2 = 500000004;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return (a%MOD*(b%MOD))%MOD;
}

int main(){
    long long N, M;
    cin >> N >> M;
    long long ans = mult(max(0LL, M-N), N);
    for(long long i = 1; i<= min((long long) (sqrt(N)), M); i++){
        ans = add(ans, N%i);
    }
    for(long long i = (long long) (sqrt(N))+1; i>1; i--){
        long long L = max((long long) (sqrt(N))+1, N/i+1), R = min(M, N/(i-1));
        long long Lm = N%L, Rm = N%R;
        if(L > R){
            continue;
        }
        ans = add(ans, mult(R-L+1, mult(inv2, Lm+Rm)));
    }
    cout << ans;
}