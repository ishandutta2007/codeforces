#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii = pair<int,int>;
using lli = long long ;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

lli k;
int main() {
    scanf("%lld",&k);
    
    lli S = k + 2000;
    printf("2000\n-1 ");
    for(int i=1;i<2000;i++) {
        printf("%lld ", min(S, 1000000ll));
        S -= min(S, 1000000ll);
    }
    return 0;
}