#include <bits/stdc++.h>
using namespace std;

int a,b,n;
int main() {
    scanf("%d%d%d",&a,&b,&n);
    
    int ans=0;
    for(int i = min(n, b); n-i <= a && i>=0; i--) ans++;
    printf("%d\n",ans);
    return 0;
}