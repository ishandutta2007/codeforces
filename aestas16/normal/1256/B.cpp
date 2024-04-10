#include <cstdio>
#include <cstring>

#define cmax(a,b) ((a)>(b)?(a):(b))
#define cswp(a,b) ((a)^=(b)^=(a)^=(b))

const int N=1e2;
int a[N+10],n;

int Get(int x) {for(int i=1;i<=n;i++) if(a[i]==x)return i;}

int main() {
    int t;scanf("%d",&t);
    while(t--) {
        int x=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) {
            int f=Get(i);
            for(int j=f;j>x;j--) {
                if(a[j-1]<a[j])break;
                cswp(a[j-1],a[j]);
            }
            x=cmax(x,f);
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}