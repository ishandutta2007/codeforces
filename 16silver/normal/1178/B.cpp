#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

char s[1010101];
long long dp[3][1000011];

int main(){
    scanf("%s",s);
    int l = strlen(s);
    dp[0][0]=0LL;
    dp[1][0]=0LL;
    dp[2][0]=0LL;
    dp[0][1]=0LL;
    dp[1][1]=0LL;
    dp[2][1]=0LL;
    for(int i=2;i<=l;i++){
        if(s[i-1]=='v' && s[i-2]=='v'){
            dp[0][i] = dp[0][i-1] + 1LL;
            dp[2][i] = dp[2][i-1] + dp[1][i-2];
        }
        else{
            dp[0][i] = dp[0][i-1];
            dp[2][i] = dp[2][i-1];
        }
        if(s[i-1]=='o'){
            dp[1][i] = dp[1][i-1] + dp[0][i-1];
        }
        else{
            dp[1][i] = dp[1][i-1];
        }
    }
    printf("%lld\n",dp[2][l]);
}