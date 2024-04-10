#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,arr[20][20];

bool check() {
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<m;j++) if(arr[i][j]!=j+1) {
            cnt++;
        }
        if(cnt > 2) return false;
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);

    if(check()) {
        puts("YES");
        return 0;
    }
    for(int i=0;i<m;i++)for(int j=i+1;j<m;j++) {
        for(int k=0;k<n;k++) swap(arr[k][i],arr[k][j]);
        if(check()) {
            puts("YES");
            return 0;
        }
        for(int k=0;k<n;k++) swap(arr[k][i],arr[k][j]);
    }
    puts("NO");

    return 0;
}