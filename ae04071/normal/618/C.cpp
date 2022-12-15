#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

pair<pii,int> arr[100000];
int n;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d",&arr[i].first.first,&arr[i].first.second);
        arr[i].second=i+1;
    }
    sort(arr,arr+n);
    
    int ox=arr[0].first.first - arr[1].first.first, oy=arr[0].first.second - arr[1].first.second;
    int g=__gcd(abs(ox), abs(oy));
    ox/=g; oy/=g;
    
    for(int i=2;i<n;i++) {
        int tx=(arr[0].first.first - arr[i].first.first), ty=arr[0].first.second-arr[i].first.second;
        g=__gcd(abs(tx),abs(ty));
        tx/=g; ty/=g;
        if(1ll*ox*ty - 1ll*oy*tx!=0) {
            printf("%d %d %d\n",arr[0].second,arr[1].second,arr[i].second);
            return 0;
        }
    }
    return 0;
}