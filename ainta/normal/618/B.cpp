#include<stdio.h>
#include<algorithm>
using namespace std;
int n, i, j, a, w[60], r[60];
bool v[60];
struct A{
    int a, b;
    bool operator<(const A &p)const{
        return a<p.a;
    }
}P[60];
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a);
            if(w[i]<a)w[i]=a;
        }
        P[i].b = i, P[i].a = w[i];
    }
    sort(P+1,P+n+1);
    for(i=1;i<=n;i++){
        r[P[i].b] = i;
    }
    for(i=1;i<=n;i++)printf("%d ",r[i]);
}