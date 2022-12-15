#include <bits/stdc++.h>
using namespace std;

int n,a[200000];

inline int _abs(int a) {return a<0 ? -a : a;}
int main() {
    scanf("%d",&n);
    
    int s=0;
    long long ans=0;
    for(int i=0;i<n;i++) {
        scanf("%d",a+i);
        ans += _abs(a[i]-s);
        s=a[i];
    }
    printf("%lld\n",ans);

    return 0;
}