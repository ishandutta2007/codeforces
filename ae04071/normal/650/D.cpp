#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

struct td{
    int b,qi,lv,rv;
    td() {}
    td(int b,int qi):b(b),qi(qi),lv(0),rv(0){}
};
int n,m,arr[400001];
vector<td> qa[400001];
int ans[400001],cnt[400001],ta[400001],k;
int lc[400001],rc[400001];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);

    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        qa[a].push_back(td(b,i));
    }
    
    k=0;
    for(int i=1;i<=n;i++) {
        int oi = lower_bound(ta,ta+k,arr[i])-ta;
        lc[i] = oi;
        
        for(auto &it:qa[i]) {
            int idx=lower_bound(ta,ta+k,it.b)-ta;
            it.lv=idx;
        }
        if(oi==k) ta[k++]=arr[i];
        else {
            ta[oi] = arr[i];
        }
    }
    k=0;
    for(int i=n;i;i--) {
        int oi = lower_bound(ta,ta+k,-arr[i])-ta;
        rc[i] = oi;

        for(auto &it:qa[i]) {
            int idx = lower_bound(ta,ta+k,-it.b)-ta;
            it.rv=idx;
        }
        if(oi==k) ta[k++]=-arr[i];
        else {
            ta[oi]=-arr[i];
        }
    }
    for(int i=1;i<=n;i++) for(auto &it:qa[i]) {
        ans[it.qi]=it.lv+it.rv+1;
    }
    for(int i=1;i<=n;i++) {
        if(lc[i]+rc[i]+1==k) cnt[lc[i]]++;
    }
    for(int i=1;i<=n;i++) {
        int v=(lc[i]+rc[i]+1==k && cnt[lc[i]]==1 ? k-1 : k);
        for(auto &it:qa[i]) ans[it.qi] = max(ans[it.qi],v);
    }
    //puts("=========");
    
    
    
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    
    
    return 0;
}