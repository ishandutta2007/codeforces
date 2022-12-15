#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int n,dp[5010][5010];;
char str[5010];

int pos[5010],ord[5010],nxt[5010][5010];

int main() {
    scanf("%d",&n);
    scanf("%s",str);

    for(int i=n-2;i>=0;i--) for(int j=i+1;j<n;j++) {
        if(str[i]==str[j]) nxt[i][j] = nxt[i+1][j+1]+1;
    }

    for(int i=0;i<n;i++) dp[0][i] = 1;
    for(int i=1;i<n;i++) {
        int cnt=0,j=i,k=i-1;
        if(str[i]=='0') continue;
        for(;j<n;j++) {
            while(k>=0) {
                int l=nxt[k][i];
                if(i-k > j-i+1 || (i-k==j-i+1 && (l>=i-k || str[k+l] > str[i+l]))) break;
                cnt = (cnt + dp[k][i-1])%MOD;
                k--;
            }
            dp[i][j] = (dp[i][j] + cnt)%MOD;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) ans = (ans+dp[i][n-1])%MOD;
    printf("%d\n",ans);

    return 0;
}