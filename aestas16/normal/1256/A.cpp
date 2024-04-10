#include <cstdio>

int main() {
    int t;scanf("%d",&t);
    while(t--) {
        int a,b,n,s,f;scanf("%d%d%d%d",&a,&b,&n,&s);
        f=s/n;
        if(a<f)f=a*n;
        else f*=n;
        if(s-f<=b)puts("YES");
        else puts("NO");
    }
    return 0;
}