#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,vis[51];
char str[51][51];
lli arr[51];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",str[i]);
        for(int j=0;j<m;j++) {
            if(str[i][j] == '#') arr[i] |= 1ll << j;
        }
    }
    sort(arr,arr+n);
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && arr[i] == arr[j];j++) {
            for(int k=0;k<m;k++) if(arr[j]>>k&1) {
                if(vis[k]) {
                    puts("No");
                    return 0;
                }
            }
        }
        for(j=i;j<n && arr[i] == arr[j];j++) {
            for(int k=0;k<m;k++) if(arr[j]>>k&1) {
                vis[k] = 1;
            }
        }
    }
    puts("YES");
    return 0;
}