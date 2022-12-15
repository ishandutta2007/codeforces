#include <bits/stdc++.h>
using namespace std;

int n,arr[100000];
int main() {
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",arr+i);
        if(arr[i]%2==0) {
            ans+=arr[i];
            n--;i--;continue;
        }
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=1;i-=2) ans += arr[i]+arr[i-1];
    printf("%lld\n",ans);
    return 0;
}