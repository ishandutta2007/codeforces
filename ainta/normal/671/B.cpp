#include<stdio.h>
#include<algorithm>
using namespace std;
long long S[501000], K, MM;
int n, w[501000], pp, ww[501000];
bool Pos1(int a){
    long long ss = 0;
    for(int i=1;i<=n;i++)if(w[i] < a) ss += a-w[i];
    if(ss>K)return false;
    return true;
}
bool Pos2(int a){
    long long ss = 0;
    for(int i=1;i<=n;i++)if(w[i] > a) ss += w[i]-a;
    if(ss>K)return false;
    return true;
}
int main(){
    int i, be, ed, mid, a1, a2;
    scanf("%d%lld",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++)S[i] = S[i-1] + w[i];
    for(i=1;i<=n;i++){
        ww[i] = S[n]/n;
        if(S[n]%n >= (n-i+1))ww[i]++;
        if(ww[i] > w[i]) MM += ww[i] - w[i];
    }
    if(MM <= K){
        if(S[n]%n == 0)printf("0\n");
        else printf("1\n");
        return 0;
    }
    be = w[1], ed = S[n]/n;
    while(be<=ed){
        mid = (be+ed)>>1;
        if(Pos1(mid)){
            a1 = mid;
            be = mid + 1;
        }
        else ed = mid - 1;
    }
    be = S[n]/n, ed = w[n];
    while(be<=ed){
        mid = (be+ed)>>1;
        if(Pos2(mid)){
            a2 = mid;
            ed = mid - 1;
        }
        else be = mid + 1;
    }
    printf("%d\n",a2 - a1);
}