#include <iostream>
#include <fstream>

using namespace std;

/*
ifstream fin("test.in");
#define cin fin
*/


#define maxN 30000
#define vary 500
#define INF 1000000000

long n,d,i,j,x;
long v[maxN+11];
long dp[maxN+11][(vary<<1)+11];

long ans;

int main()
{
    cin >> n >> d;
    for(i=1;i<=n;i++){
        cin >> x;
        v[x]++;
    }
    for(i=0;i<=maxN;i++)
        for(j=0;j<=vary*2+5;j++) dp[i][j] = -INF;
    ans = -INF;

    dp[d][vary] = v[d]; ans = v[d];
    for(i=d+1;i<=maxN;i++){
        for(j=vary*2;j>=0;j--){
            if(d+j-vary <=0) continue;
            long newPos = i - (d+j-vary);
            if(newPos < 0) continue;

            dp[i][j] = max(dp[newPos][j]+ v[i],dp[newPos][j+1]+ v[i]);
            if(j) dp[i][j] = max(dp[i][j],dp[newPos][j-1]+ v[i]);

            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}