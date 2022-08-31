
#include<bits/stdc++.h>
using namespace std;
int n, m, K, X[30];
char p[30], q[30];
char tp[30], tq[30];
int A[1<<21], B[1<<21], Path[1<<21];
struct point{
    int a, b;
}w[1<<21];
int D[1<<21];
int Q[1<<21];
void Go(int a, int pv){
    if(!D[a])return;
    D[a]=0;
    int head=0,tail=0;
    Q[++tail]=a;
    while(head<tail){
        int x = Q[++head];
        Path[x]=pv;
        for(int i=0;i<K;i++){
            if(D[x^(1<<i)]>D[x]+1){
                D[x^(1<<i)]=D[x]+1;
                Q[++tail]=x^(1<<i);
            }
        }
    }
}
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s",p);
    scanf("%s",q);
    for(i=0;i<K;i++)X[i]=i;
    for(i=0;i<K;i++)tp[i]=p[i],tq[i]=q[i];
    for(i=0;i<=n;i++){
        if(i){
            scanf("%d%d",&w[i].a,&w[i].b);
            w[i].a--,w[i].b--;
            swap(X[w[i].a],X[w[i].b]);
        }
        int sp=0,sq=0;
        for(j=0;j<K;j++){
            tp[X[j]]=p[j];
            tq[X[j]]=q[j];
        }
        for(j=0;j<K;j++){

            sp+=((tp[j]-'0')<<j);
            sq+=((tq[j]-'0')<<j);
        }
        A[i]=sp,B[i]=sq;
    }
    int res=1e9;
    for(i=0;i<(1<<K);i++)D[i]=1e9;
    int bb=-1,ee=-1;
    for(i=0;i<=n-m;i++){
        Go(A[i],i);
        if(res>D[B[i+m]]){
            res=D[B[i+m]];
            bb=Path[B[i+m]]+1,ee=i+m;
        }
    }
    printf("%d\n%d %d\n",K-res,bb,ee);
}