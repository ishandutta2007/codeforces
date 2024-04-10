#include<stdio.h>
#include<algorithm>
using namespace std;
int w[201000], C[201000], Prv[201000], be[201000], MM[201000];
int n, S, P[201000], cnt, Res;
int Do(int S, int pv){
    if(!S)return 0;
    if(!pv)return 1;
    int t = w[pv], b;
    b = be[t];
    if(pv-b+1 <= S / t){
        S -= (pv-b+1) * t;
    }
    else{
        S = S%t;
    }
    return Do(S,b-1);
}
int main(){
    int i, pv, T = 0;
    scanf("%d%d",&S,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        C[w[i]]++;
    }
    int tp = 0;
    for(i=1;i<=S;i++){
        if(C[i]){
            Prv[i] = tp;
            tp = i;
        }
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        if(!be[w[i]]) be[w[i]] = i;
    }
    pv = 0;
    for(i=1;i<=S;i++){
        while(pv<n && w[pv+1] <= i)pv++;
        MM[i] = pv;
    }
    for(i=n;i>=1;i--){
        if(T+w[i] <= S){
            P[++cnt] = i;
            T += w[i];
        }
    }
    pv = 0;
    T = 0;
    Res = S+1;
    for(i=S-1;i>=1;i--){
        while(pv<cnt && w[P[pv+1]] + T + i <= S){
            pv++;
            T+=w[P[pv]];
        }
        if(pv < n && w[P[pv+1]] > i){
            continue;
        }
        if(Do(S-T-i, min(MM[S-T-i], P[pv+1]))){
            Res = i;
        }
    }
    if(Res>S)printf("Greed is good\n");
    else printf("%d\n",Res);
}