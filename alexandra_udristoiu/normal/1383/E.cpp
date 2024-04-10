#include<iostream>
#include<cstring>
#define DIM 1000005
#define mod 1000000007
using namespace std;
int n, i, nr, sum, sol;
char s[DIM];
int nxt[DIM], d[DIM], r[DIM];
int modulo(int x){
    if(x < 0){
        return x + mod;
    }
    if(x >= mod){
        return x - mod;
    }
    return x;
}
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    nxt[n] = n + 1;
    for(i = n - 1; i >= 0; i--){
        if(s[i + 1] == '1'){
            nxt[i] = i + 1;
        }
        else{
            nxt[i] = nxt[i + 1];
        }
    }
    if(nxt[0] == n + 1){
        cout<< n;
        return 0;
    }
    d[ nxt[0] ] = 1;
    for(i = nxt[0]; i <= n; i++){
        if(s[i] == '1'){
            nr = 0;
            sum = modulo(sum + d[i]);
        }
        else{
            nr++;
            d[i] = modulo(sum - r[nr]);
            r[nr] = sum;
        }
        d[ nxt[i] ] = modulo(d[ nxt[i] ] + d[i]);
        if(s[i] == '1'){
            sol = modulo(sol + d[i]);
        }
    }
    sol = sol * 1LL * (nxt[0]) % mod * (nr + 1) % mod;
    cout<< sol;
}