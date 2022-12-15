#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli INF=1000000000000000000ll;

int n,k;
lli b,c;
int arr[200001],cnt[200001][5];
lli ps[200001][5];

priority_queue<lli> que[5];
lli sum[5];

void push(lli val) {
    for(int i=0;i<5;i++) {
        int t=(val+i)%5;
        lli v=i*c - (val+i)/5*b;
        que[t].push(v);
        sum[t]+=v;
        if(que[t].size()>k) {
            sum[t]-=que[t].top();
            que[t].pop();
        }
    }
}
lli get(lli val) {
    int t=val%5;
    if(que[t].size()<k) return INF;
    return val/5*b*k + sum[t];
}
int main() {
    scanf("%d%d%lld%lld",&n,&k,&b,&c);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    sort(arr+1,arr+n+1);
    
    if(arr[1] < 0) {
        lli v=-arr[1];
        for(int i=1;i<=n;i++) arr[i]+=v;
    }
    
    if(c*5<=b) {
        lli s=0,ans=INF;
        for(int i=1,j=1;j<=n;j++) {
            while(j-i+1>k) s-=arr[i++];
            s+=arr[j];
            if(j-i+1==k) ans = min(ans, (1ll*arr[j]*k-s)*c);
        }
        printf("%lld\n",ans);
        return 0;
    }
    
    lli ans=INF;
    for(int i=1;i<=n;i++) {
        push(arr[i]);
        for(int j=arr[i];j<arr[i]+5;j++) ans = min(ans,get(j));
    }
    printf("%lld\n",ans);
    
    return 0;
}