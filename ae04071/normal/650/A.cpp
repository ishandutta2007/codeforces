#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
using lli = long long;

pii arr[200000];
int n;
lli get() {
    lli ret=0;
    sort(arr,arr+n);
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && arr[i].fi==arr[j].fi;j++);
        ret += 1ll*(j-i)*(j-i-1)/2;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&arr[i].fi,&arr[i].se);
    lli ans=0;
    ans += get();
    for(int i=0;i<n;i++) swap(arr[i].fi,arr[i].se);
    ans += get();
    
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && arr[i]==arr[j];j++);
        ans -= 1ll*(j-i)*(j-i-1)/2;
    }
    
    printf("%lld\n",ans);

    return 0;
}