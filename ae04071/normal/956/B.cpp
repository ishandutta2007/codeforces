#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,arr[100000];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    
    double ans = -1;
    for(int i=0,j=0;i<n;i++) {
        for(;j<n && arr[j] - arr[i] <= m; j++);
        if(i+1<j-1) {
            ans = max(ans, 1.0*(arr[j-1]-arr[i+1]) / (arr[j-1] - arr[i]));
        }
    }
    if(ans < -0.5) {
        puts("-1");
    } else printf("%.10lf\n",ans);

    return 0;
}