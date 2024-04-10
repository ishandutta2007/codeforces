#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int x, ck;
    bool operator<(const A &p)const{
        return x<p.x;
    }
}w[401000];
int n, m, S, Res, p1, p2, r1, r2;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].x);
        w[i].ck=1;
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d",&w[n+i].x);
        w[n+i].ck=-1;
    }
    Res = S = (n-m)*2;
    r1=p1 = 2*n, r2=p2 = 2*m;
    sort(w+1,w+n+m+1);
    for(i=n+m;i>=1;i--){
        if(w[i].ck==1)p1++,S++;
        else p2++,S--;

        if(Res <= S && (w[i].x != w[i-1].x || i == 1)){
            Res = S;
            r1=p1,r2=p2;
        }
    }
    printf("%d:%d\n",r1,r2);
}