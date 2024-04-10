#include<stdio.h>
#include<algorithm>
using namespace std;
int n, k, BIT[1010000], cur = 1;
long long S = 1;
int Sum(int a){
    int r = 0;
    while(a){
        r+=BIT[a];
        a-=(a&-a);
    }
    return r;
}
void Ins(int a){
    while(a<=n){
        BIT[a]++;
        a+=(a&-a);
    }
}
int main(){
    int i, nxt, tp;
    scanf("%d%d",&n,&k);
    if(k*2>n)k=n-k;
    for(i=1;i<=n;i++){
        nxt = cur + k;
        if(nxt > n){
            nxt -= n;
            tp = Sum(n) - Sum(cur) + Sum(nxt-1);
        }
        else{
            tp = Sum(nxt-1)-Sum(cur);
        }
        Ins(cur);
        Ins(nxt);
        S += tp+1;
        printf("%lld ",S);
        cur = nxt;
    }
}