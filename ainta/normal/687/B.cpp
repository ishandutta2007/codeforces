#include<stdio.h>
#include<algorithm>
int n, K;
int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int i, t, r = 1, a;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        t = gcd(a,K);
        r = r/gcd(r,t)*t;
    }
    printf(r==K?"Yes\n":"No\n");
}