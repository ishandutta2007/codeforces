#include<stdio.h>
#include<algorithm>
#define SZ 131072
using namespace std;
int n, w[SZ];
struct Tree{
    int M, S;
}IT[SZ+SZ];
void Ins(int a, int b){
    a += SZ;
    IT[a].S += b;
    IT[a].M = max(0,IT[a].S);
    while(a!=1){
        a>>=1;
        IT[a].S = IT[a*2].S + IT[a*2+1].S;
        IT[a].M = max(IT[a*2].M, IT[a*2].S + IT[a*2+1].M);
    }
}
int Find(int nd){
    int TT = 0;
    while(nd < SZ){
        nd*=2;
        if(IT[nd].M <= TT){
            TT -= IT[nd].S;
            nd++;
        }
    }
    return nd-SZ;
}
int main(){
    int i, p, ck, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&p,&ck);
        if(ck == 1){
            scanf("%d",&a);
            Ins(n + 1 - p, 1);
            w[p] = a;
        }
        else{
            Ins(n + 1 - p, -1);
        }
        if(IT[1].M <= 0){
            printf("-1\n");
        }
        else{
            printf("%d\n",w[n+1-Find(1)]);
        }
    }
}