#include <bits/stdc++.h>
using namespace std;

const int INF=1000000000;
int dp[31][31][51];
int DP(int n,int m,int k) {
    int &ret=dp[n][m][k];
    if(ret!=-1) return ret;

    if(n*m<k) return ret = INF;
    else if(n*m==k || k==0) return ret=0;
    else if(k==0) return ret=0;

    ret = INF;
    for(int i=1;i<n;i++) for(int j=0;j<=k;j++) {
        ret = min(ret, DP(i,m,j)+DP(n-i,m,k-j)+m*m);
    }
    for(int i=1;i<m;i++) for(int j=0;j<=k;j++) {
        ret = min(ret, DP(n,i,j)+DP(n,m-i,k-j)+n*n);
    }
    return ret;
}

int main() {
    int test;
    scanf("%d",&test);
    memset(dp,-1,sizeof(dp));
    while(test--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",DP(n,m,k));   
    }
    return 0;
}