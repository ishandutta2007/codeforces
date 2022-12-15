#include <bits/stdc++.h>
using namespace std;

int n,a[300000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    int mx=0;
    for(int i=n-1;i>=0;i--) if(a[i]!=a[0]) {
        mx=max(mx,i);
        break;
    }
    
    reverse(a,a+n);
    for(int i=n-1;i>=0;i--) if(a[i]!=a[0]) {
        mx=max(mx,i);
        break;
    }

    printf("%d\n",mx);
    
    return 0;
}