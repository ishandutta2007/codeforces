#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii = pair<int,int>;
using lli = long long ;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m;
int cnt[5000],l[5000];
inline int get(int a,int b) {
    if(a<b) return b-a;
    else return n-a+b;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        
        int t = get(a,b);
        if(!cnt[a]) l[a]=t;
        else l[a]=min(l[a],t);
        cnt[a]++;
    }

    lli ans = 1000000000000000000ll;
    for(int i=0;i<n;i++) {
        lli mx=0;
        int c=0,j=i;
        do {
            mx = max(mx,c + 1ll*(cnt[j]-1)*n + l[j]);
            j = (j+1)%n;
            c++;
        }while(j!=i);
        printf("%lld ",mx);
        ans = min(ans,mx);
    }

    return 0;
}