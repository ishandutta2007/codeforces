using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

long long fct[1000];
long long ifct[1000];
long long two[1000];
long long m;

long long choose(long long a, long long b){
    return ((fct[a] * ifct[b])%m * ifct[a-b])%m;
}

long long power(long long a, long long b){
  if(b == 0) return 1;
  long long y = power(a, b/2);
  if(b%2 == 0) return ((y*y) %m);
  return (((y*y)%m)*a)%m;
}

long long inverse(long long a){
    return power(a, m-2);
}
    long long dp[403][403];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long long n;
    cin >> n >> m;

    
    fct[0] = 1;
    two[0] = 1;
    for(int i=1; i<999; i++){
        two[i] = two[i-1]*2;
        two[i]%=m;
    }
        for (long long i = 1; i < 1000; i++) {
            fct[i] = (fct[i - 1] * i)%m;
        }
        ifct[1000 - 1] =inverse(fct[1000 - 1]);
        for (long long i = 1000 - 2; i >= 0; i--) {
            ifct[i] = (ifct[i + 1] * (i + 1))%m;
        }


    for(long long i=0; i<=n; i++){

        for(long long j=1; j<=i; j++){
            if(i == 0){
                dp[i][0] = 1;
                continue;
            }
            if(i == 1){
                dp[i][0] = 0;
                dp[i][1] = 1;
                continue;
            }
            if(j == i-1) continue;
            if(j == i){
                dp[i][i] += two[i-1];
                dp[i][i]%=m;
                continue;
            }
            //[sequence of j] [split] [sequence of i-j-1]
            for(long long k=0; k<=i-j-1; k++){
                dp[i][k+j] += (((dp[i-j-1][k] * two[j-1])%m) * choose(k+j, j))%m;
                dp[i][j+k]%=m;
            }
        }
    }
    long long s = 0;
    for(long long i=0; i<=n; i++){
        s += dp[n][i];
        s%=m;
    }
    cout << s << endl;
    
}