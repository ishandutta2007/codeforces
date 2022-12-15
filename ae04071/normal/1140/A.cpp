#include <bits/stdc++.h>
using namespace std;

int n,a[10001];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    int s=0;
    for(int i=1;i<=n;) {
        int mx=i;
        while(i<=mx) mx=max(mx,a[i++]);
        s++;
    }
    printf("%d\n",s);
    return 0;
}