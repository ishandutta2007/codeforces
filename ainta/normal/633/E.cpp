#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int a,b;
}w[1010000];
int M1, M2, n, K, Deq1[1010000],Deq2[1010000], h1, t1, h2, t2, Right[1010000], R[1010000];
long double Res, tp;
int main(){
    int i, pv;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)scanf("%d",&w[i].a);
    for(i=1;i<=n;i++)scanf("%d",&w[i].b);
    pv = 1;
    h1=h2=1;
    for(i=1;i<=n;i++){
        while(h1<=t1 && Deq1[h1] < i)h1++;
        while(h2<=t2 && Deq2[h2] < i)h2++;
        if(pv<i)pv = i;
        while(pv<=n && (h1>t1 || h2>t2 || w[Deq1[h1]].a*100 < w[Deq2[h2]].b)){
            while(h1<=t1 && w[Deq1[t1]].a <= w[pv].a)t1--;
            while(h2<=t2 && w[Deq2[t2]].b >= w[pv].b)t2--;
            Deq1[++t1] = pv;
            Deq2[++t2] = pv;
            pv++;
        }
        R[i] = min(w[Deq1[h1]].a*100, w[Deq2[h2]].b);
        Right[i] = pv-1;
    }
    h1=h2=1,t1=t2=0;
    pv = 1;
    for(i=1;i<=n;i++){
        while(h1<=t1 && Deq1[h1] < i)h1++;
        while(h2<=t2 && Deq2[h2] < i)h2++;
        if(pv<i)pv = i;
        while(pv<Right[i]){
            while(h1<=t1 && w[Deq1[t1]].a <= w[pv].a)t1--;
            while(h2<=t2 && w[Deq2[t2]].b >= w[pv].b)t2--;
            Deq1[++t1] = pv;
            Deq2[++t2] = pv;
            pv++;
        }
        if(h1<=t1 && h2<=t2)R[i] = max(R[i],min(w[Deq1[h1]].a*100, w[Deq2[h2]].b));
    }
    sort(R+1,R+n+1);
    tp = (long double)K/n;
    for(i=1;i<=n-K+1;i++){
        Res += R[i]*tp;
        tp = tp*(n-i-K+1)/(n-i);
    }
    printf("%.11Lf\n",Res);
    return 0;
}