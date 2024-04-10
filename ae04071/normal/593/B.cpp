#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n;
pll a[100000];

inline lli get(pll line,lli pos) {
    return line.fi*pos + line.se;
}
int main() {
    lli x1,x2;
    scanf("%d%lld%lld",&n,&x1,&x2);
    for(int i=0;i<n;i++) scanf("%lld%lld",&a[i].fi,&a[i].se);
    sort(a,a+n, [&](const pll &a,const pll &b) {
        lli av=a.fi*x1+a.se, bv=b.fi*x1+b.se;
        if(av==bv) return a.fi*x2+a.se < b.fi*x2+b.se;
        else return av<bv;
    });

    for(int i=1;i<n;i++) {
        if(get(a[i-1],x1) == get(a[i],x1)) continue;
        if(get(a[i-1],x2) > get(a[i],x2)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}