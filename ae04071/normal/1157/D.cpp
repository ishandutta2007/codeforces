#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,k;
lli arr[100001];
int main() {
    scanf("%d%d",&n,&k);
    if(1ll*k*(k+1)/2>n) {
        puts("NO");
        return 0;
    }

    int lo=1,up=1e9+1;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(1ll*k*(2ll*md+(k-1))/2 <= n) lo=md;
        else up=md;
    }
    lli s=1ll*k*(2ll*lo+(k-1))/2;
    arr[1]=lo;
    for(int i=2;i<=k;i++) {
        if(s+(arr[i-1]*2-arr[i-1]-1)*(k-i+1)<=n) {
            s+=(arr[i-1]*2-arr[i-1]-1)*(k-i+1);
            arr[i]=arr[i-1]*2;
        } else {
            int lo=arr[i-1]+1,up=arr[i-1]*2;
            while(up-lo>1) {
                int md=(lo+up)>>1;
                if(s+(md-arr[i-1]-1)*(k-i+1)<=n) lo=md;
                else up=md;
            }
            arr[i]=lo;
            s+=(lo-arr[i-1]-1)*(k-i+1);
        }
    }
    if(s!=n) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=1;i<=k;i++) printf("%lld ",arr[i]);
    
    return 0;
}