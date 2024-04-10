#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;

int n,k;
lli arr[300001];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i),arr[i]+=arr[i-1];
    
    priority_queue<lli> que;
    lli ans=-1e18,sum=0;
    for(int i=1;i<n;i++) {
        sum+=arr[i];
        que.push(arr[i]);
        while(que.size()>k-1) sum-=que.top(),que.pop();
        if(que.size()==k-1) ans = max(ans, k*arr[n]-sum);
    }
    printf("%lld\n",ans);
    
    return 0;
}