#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long epow(long long a, long long x){
    long long res = 1;
    while(x>0){
        if(x%2 == 1){
            res = res*a;
            res = res % MOD;
        }
        x = (x>>1);
        a = a*a;
        a = a%MOD;
    }
    return res;
}
long long modInverse(long long b){
    long long ex = MOD - 2;
    if (b==1){
        return 1;
    }
    long long r = 1;
    while (ex ){
        if (ex&1){
            r=(r * b)%MOD;
        }
        ex = ex >> 1;
        b = (b * b)%MOD;
    }
    return r;
}
long long divide(long long a, long long b){
    long long x = modInverse(b);
    return (a*x)%MOD;
}
int main(){
    long long k;
    cin >> k;
    long long res = 2;
    long long toAdd = -1;
    //return 0;
    for(long long i = 0; i<k; i++){
        long long a;
        cin >> a;
        if(a%2 == 0){
            toAdd = 1;
        }
        res = epow(res, a);
    }
    res = divide(res, 2);
    long long num = divide(res+toAdd, 3);
    cout << num << "/" << res;
    return 0;
}