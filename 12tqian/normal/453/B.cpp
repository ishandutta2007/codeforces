#include <bits/stdc++.h>
using namespace std;
static long fact [60];
static long a[100];
static long primes[17] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
static long b[100][1<<17];
static long dp[100][1<<17];
static long n;
long calc(long i, long mask){
    if(i == n){
        return 0;
    }
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    long ans = 10000000;
    for(long k = 1; k< 60; k++){
        if((fact[k] & mask) == 0){
            long temp = calc(i+1, (mask|fact[k])) + abs(k-a[i]);
            if(temp<ans){
                ans = temp;
                b[i][mask] = k;
              //  cout<<k<< endl;
            }
        }
    }
    dp[i][mask] = ans;
    return ans;
}
int main(){
    scanf("%d", &n);
    for(long i = 0; i<n; i++){
        long d;
        scanf("%d", &d);
        a[i] = d;
    }
    for(long i = 1; i<60; i++){
        long total = 0;
        for(long x = 0; x<17; x++){
            if(i%primes[x] == 0){
                total += (1<<x);
            }
        }
        fact[i] = total;
    }
    for(long y = 0; y<100; y++){
        for(long z = 0; z<(1<<17); z++){
            dp[y][z] = -1;
        }
    }
    long ans = calc(0,0);
    //cout<< ans << endl;
    long temp = 0;
    for(long i=0;i<n;i++){
        cout<< b[i][temp]<< " ";
        temp = temp | fact[b[i][temp]];
    }
    return 0;
}