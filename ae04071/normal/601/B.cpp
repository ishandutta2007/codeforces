#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,q,a[100000],b[100000];
struct td{
    int l,r,v;
    td() {}
    td(int l,int r,int v):l(l),r(r),v(v) {}
};
lli solve(int l,int r) {
    lli ret=0,sum=0;
    stack<td> stk;
    for(int i=l;i<r;i++) {
        int ll=i;
        while(!stk.empty() && stk.top().v <= b[i]) {
            td cur=stk.top();
            sum -= 1ll*(cur.r-cur.l+1)*cur.v;
            ll = cur.l;
            stk.pop();
        }
        sum += 1ll*(i-ll+1)*b[i];
        stk.push(td(ll,i,b[i]));
        ret += sum;
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n-1;i++) b[i]=abs(a[i+1]-a[i]);
    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        l--;r--;
        printf("%lld\n",solve(l,r));
    }
    return 0;
}