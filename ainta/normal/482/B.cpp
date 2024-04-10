#include<stdio.h>
#define SZ 131072
int n,m, IT[SZ+SZ+1], w[SZ], IT2[SZ+SZ+1];
void Ins(int b, int e, int a){
    b+=SZ,e+=SZ;
    while(b<=e){
        IT[b]|=a;
        IT[e]|=a;
        b=(b+1)>>1,e=(e-1)>>1;
    }
}
int Gap(int a){
    a+=SZ;
    int r = 0;
    while(a){
        r|=IT[a];
        a>>=1;
    }
    return r;
}
void Ins2(int a, int b){
    a+=SZ;
    IT2[a]=b;
    while(a!=1){
        a>>=1;
        IT2[a]=(IT2[a*2]&IT2[a*2+1]);
    }
}
struct Query{
    int b, e, q;
}Q[101000];
int Calc(int b, int e){
    int r = (1<<30)-1;
    b+=SZ,e+=SZ;
    while(b<=e){
        r &= IT2[b];
        r &= IT2[e];
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
int main(){
    int i, a, b, e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&b,&e,&a);
        Ins(b,e,a);
        Q[i].b=b,Q[i].e=e,Q[i].q=a;
    }
    for(i=1;i<=n;i++)w[i]=Gap(i);
    for(i=1;i<=n;i++){
        Ins2(i,w[i]);
    }
    for(i=1;i<=m;i++){
        if(Calc(Q[i].b,Q[i].e)!=Q[i].q){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(i=1;i<=n;i++)printf("%d ",w[i]);
}