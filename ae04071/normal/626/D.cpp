#include <bits/stdc++.h>
using namespace std;

double dp[10001],cnt[5001];
int n,arr[2000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int v=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j && arr[i]>arr[j]) {
        v++;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j && arr[i]>arr[j]) {
        cnt[arr[i]-arr[j]] += 1.0/v;
    }
    for(int i=0;i<5000;i++) dp[i] = cnt[i];
    for(int i=4999;i>=0;i--) {
        for(int j=0;j<5000;j++) dp[i+j] += dp[i]*cnt[j];
        dp[i]=0;
    }
    
    double ans=0,s=0;
    for(int i=0;i<5000;i++) {
        ans+=s*cnt[i];
        s+=dp[i];
    }
    printf("%.10lf\n",ans);
    
    return 0;
}