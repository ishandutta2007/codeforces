#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli=long long;
using pii=pair<lli,int>;

int n,a[300000];
int main() {
    lli ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",a+i);
    }
    
    lli rem=0;
    for(int i=0;i<n;i++) {
        lli v = min(a[i]/2ll, rem);
        a[i]-=v*2;
        rem-=v;
        ans+=v+a[i]/3;
        a[i]%=3;
        rem+=a[i];
    }
    printf("%lld\n",ans);
    
    return 0;
}