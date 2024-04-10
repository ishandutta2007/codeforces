#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 131072
#define INF 999999999
int n, s, l, w[101000], Deq1[101000], h1, t1, Deq2[101000], h2, t2, D[101000];
int IT[SZ+SZ+1];
void Ins(int a, int b){
    a+=SZ;
    IT[a]=b;
    while(a!=1){
        a>>=1;
        IT[a] = min(IT[a*2],IT[a*2+1]);
    }
}
int Min(int b, int e){
    int r = INF;
    b+=SZ,e+=SZ;
    while(b<=e){
        r=min(r,IT[b]);
        r=min(r,IT[e]);
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
int main()
{
    int i, be = 1;
    scanf("%d%d%d",&n,&s,&l);
    h1=1,t1=0;
    h2=1,t2=0;
    Ins(0,0);
    D[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        while(h1<=t1 && w[Deq1[t1]] >= w[i])t1--;
        Deq1[++t1] = i;
        while(h2<=t2 && w[Deq2[t2]] <= w[i])t2--;
        Deq2[++t2] = i;
        while(w[Deq2[h2]] - w[Deq1[h1]] > s){
            if(Deq1[h1] < Deq2[h2]){
                be = Deq1[h1]+1;
                h1++;
            }
            else{
                be = Deq2[h2]+1;
                h2++;
            }
        }
        if(be-1 > i-l){
            D[i] = INF;
            Ins(i,INF);
            continue;
        }
        D[i] = Min(be-1,i-l)+1;
        Ins(i,D[i]);
    }
    if(D[n] > n)printf("-1\n");
    else printf("%d\n",D[n]);
}