#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int,int>;

int n;
lli arr[100011],sum[100011],oa[100010];
int A,cf,cm;
lli m;

void trace(int e,int v) {
    vector<int> pos(n+1,0);
    set<pii> tr;
    for(int i=1;i<=n;i++) tr.insert({oa[i],i});
    for(int i=1;i<=n;i++){
        auto it=tr.lower_bound({arr[i],0});
        pos[i] = it->second;
        tr.erase(it);
    }
    for(int i=1;i<=n;i++) {
        if(i>=e) arr[i] = A;
        else if(arr[i]<v) arr[i] = v;
    }
    
    vector<pii> ret;
    for(int i=1;i<=n;i++) ret.push_back({pos[i],arr[i]});
    sort(ret.begin(),ret.end());
    for(auto &it:ret) printf("%d ",it.second);
}
int main() {
    scanf("%d%d%d%d%lld",&n,&A,&cf,&cm,&m);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i);
    for(int i=1;i<=n;i++) oa[i] = arr[i];
    sort(arr,arr+n+1);
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+arr[i];

    lli ans=-1,ai=-1,ml=-1;
    for(int i=n+1;i;i--) {
        if(1ll*A*(n-i+1) - (sum[n] - sum[i-1])>m) break;
        
        lli rem=m - (1ll*A*(n-i+1) - (sum[n]-sum[i-1]));
        int lo=0,up=A+1;
        while(up-lo>1) {
            int md=(lo+up)>>1;
            int idx=lower_bound(arr,arr+i,md)-arr;
            if(1ll*md*(idx-1) - sum[idx-1] <= rem) lo=md;
            else up=md;
        }
        
        lli val=1ll*cf*(n-i+1) + 1ll*cm*lo;
        if(val > ans) {
            ans = val;
            ai = i;
            ml=lo;
        }
    }
    printf("%lld\n",ans);
    trace(ai, ml);
    
    return 0;
}