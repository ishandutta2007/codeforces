#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n/2;i++) {
        for(int j=0;j<m;j++) {
            printf("%d %d\n",i+1,j+1);
            printf("%d %d\n",n-i,m-j);
        }
    }
    if(n%2==1) {
        int md = (n+1)/2;
        for(int j=0;j<m/2;j++){
            printf("%d %d\n",md,j+1);
            printf("%d %d\n",md,m-j);
        }
        if(m%2==1) {
            printf("%d %d\n",md,(m+1)/2);
        }
    }
    return 0;
}