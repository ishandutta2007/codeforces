#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&c<48)c=getchar();if(c=='-')f=-1,c=getchar();while(c>47)x=x*10+(c^48),c=getchar();return f*x;}
 
const int maxn = 3e5+7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
 
vector<pr> ans;
 
void solve(int l, int r) {
    if(r<=l) return;
    int m=1;
    while(m*2<r-l+1) m*=2;
    m+=l-1;
    solve(l,m); solve(m+1,r);
    for(int i=l, j=0; j<r-m; ++i, ++j) ans.push_back(pr(i,i+m-l+1));
}
 
int main() {
    int n=read();
    int m=1;
    while(m*2<=n) m*=2;
    solve(1,m);
    if(m!=n) solve(n-m+1,n);
    printf("%d\n", int(ans.size()));
    for(pr p: ans) printf("%d %d\n", p.first, p.second);
}