#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli,lli>;

int n;
lli arr[200001];
lli sum(int l,int r) {
    return arr[r]-arr[l-1];
}

struct td{
    int f,i,s;
    td() {}
    td(int f,int i,int s):f(f),i(i),s(s) {}
    pll get() {
        int cnt=(n-s+1)+(i-f+1);
        return pll(sum(s,n)+sum(f,i) - sum(i,i)*cnt, (n-s+1)+(i-f+1));
    }
};
        
int cmp(td a, td b) {
    pll at=a.get(), bt=b.get();
    if(at.first*bt.second < at.second*bt.first) return 1;
    else if(at.first*bt.second == at.second*bt.first) return 0;
    else return -1;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i);
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) arr[i]+=arr[i-1];

    td ans(1,1,n+1),tmp(2,2,n+1);
    for(int i=2;i<n;i++) {
        while(tmp.f>1 && tmp.s>tmp.i+1) {
            td nxt=tmp;
            nxt.f--; nxt.s--;
            if(cmp(tmp,nxt)<0) break;
            tmp=nxt;
        }
        if(cmp(ans,tmp)>0) ans=tmp;
        tmp.i++; tmp.f++;
        if(tmp.i==tmp.s)  tmp.s++, tmp.f++;
    }

    printf("%d\n",(ans.i-ans.f+1)+(n-ans.s+1));
    for(int i=ans.f;i<=ans.i;i++) printf("%lld ",arr[i]-arr[i-1]);
    for(int i=ans.s;i<=n;i++) printf("%lld ",arr[i]-arr[i-1]);
    
    return 0;
}