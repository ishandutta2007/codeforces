#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[301000], K, S[301000];
int Get(int b, int e){
    if(b>e)return 0;
    int t;
    if(!b)t = 0;
    else t = S[b-1];
    return S[e]-t;
}
bool Pos(int M){
    int i, pv1 = 0;
    S[0] = 1;
    for(i=1;i<=n;i++){
        while(w[i] - w[pv1+1] > M) pv1++;
        S[i] = S[i-1];
        if(Get(pv1,i-K))S[i]++;
    }
    return S[n]!=S[n-1];
}
int main(){
    int b = 0, e = 1e9, res, mid;
    int i;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid))res = mid, e = mid - 1;
        else b = mid + 1;
    }
    printf("%d\n",res);
}