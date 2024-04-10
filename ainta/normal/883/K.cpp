#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int bb, b, e;
}w[201000];
int n;
long long S= 0;
int main(){
    int i, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        w[i] = {a, a, a+b};
    }
    int Mx = -1e9, Mn = 1e9;
    for(i=1;i<=n;i++){
        Mx = max(Mx, w[i].b+i);
        Mn = min(Mn, w[i].e-i);
        w[i].e = min(Mn + i, w[i].e);
        w[i].b = max(Mx - i, w[i].b);
    }
    Mx = -1e9, Mn = 1e9;
    for(i=n;i>=1;i--){
        Mx = max(Mx, w[i].b-i);
        Mn = min(Mn, w[i].e+i);
        w[i].b = max(Mx + i, w[i].b);
        w[i].e = min(Mn - i, w[i].e);
    }
    for(i=1;i<=n;i++){
        if(w[i].b>w[i].e){
            printf("-1\n");
            return 0;
        }
        S += w[i].e - w[i].bb;
    }
    printf("%lld\n",S);
    for(i=1;i<=n;i++){
        printf("%d ",w[i].e);
    }
}