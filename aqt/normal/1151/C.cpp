#include <bits/stdc++.h>

using namespace std;

long long L, R;
long long MOD = 1e9+7;

long long mult(long long a, long long b){
    return (a%MOD)*(b%MOD)%MOD;
}

long long add(long long a, long long b){
    return (a%MOD+b%MOD)%MOD;
}

long long solve(long long N){
    long long odd = 0, even = 0;
    for(long long i = 0; i<=62; i++){
        if(i&1){
            if(odd+even+(1LL<<i) > N){
                even += N - odd - even;
                break;
            }
            else{
                even += (1LL<<i);
            }
        }
        else{
            if(odd+even+(1LL<<i) > N){
                odd += N - odd - even;
                break;
            }
            else{
                odd += (1LL<<i);
            }
        }
    }
    return add(mult(odd, odd), mult(even, even+1));
}

int main(){
    cin >> L >> R;
    long long ans = solve(R) - solve(L-1);
    if(ans < 0){
        ans += MOD;
    }
    cout << ans << endl;
}