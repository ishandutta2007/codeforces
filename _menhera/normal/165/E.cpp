#include <bits/stdc++.h>
using namespace std;

const int lgMAXN = 22;
const int MAXN = 1<<22;

int N;
int a[MAXN];
int dp[MAXN]; 
int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &N); for(int i=0; i<N; ++i){ scanf("%d", a+i); dp[a[i]] = a[i];}    
    for(int i=0; i<lgMAXN; ++i)
        for(int j=0; j<MAXN; ++j)
            if(!(j&(1<<i)))
                dp[j|(1<<i)] = max(dp[j], dp[j|(1<<i)]);
    for(int i=0; i<N; ++i) printf("%d ", dp[(MAXN-1)^a[i]]);
    puts("");
}