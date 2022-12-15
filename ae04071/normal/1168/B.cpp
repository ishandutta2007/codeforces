#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pll = pair<lli,lli>;
using pli = pair<lli,int>;
using pdd = pair<double,double>;

char str[300100];
int n;

bool check(int l,int r) {
    for(int i=l;i<=r;i++)for(int j=i+2;j<=r;j+=2) {
        if(str[i]==str[j] && str[j]==str[(i+j)/2]) return true;
    }
    return false;
}
lli solve(int l,int r) {
    lli ret=0;
    for(int i=l;i<=r;i++) for(int j=i;j<=r;j++) {
        bool f=check(i,j);
        if(!f) ret++;
    }
    return ret;
}
int main() {
    scanf("%s",str);
    n=strlen(str);
    lli ans=0;
    if(n<=8) {
        ans = solve(0,n-1);
    } else {
        ans = solve(0,8);
        for(int j=9;j<n;j++) {
            for(int i=j-8;i<=j;i++) {
                if(!check(i,j)) ans++;
            }
        }
    }
    printf("%lld\n",1ll*n*(n+1)/2 - ans);
    
    return 0;
}