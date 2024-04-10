#include<cstdio>
int n, K, w[1010], D[10100], P[1010], cnt;
int Q[10100], BASE = 4000, head, tail;
void Ins(int a, int b){
    if(a>BASE || a < -BASE)return;
    if(D[a+BASE])return;
    D[a+BASE] = b;
    Q[++tail] = a;
}
int main(){
    int i, a, ck1 = 0, ck2 = 0;
    scanf("%d%d",&n,&K);
    for(i=1;i<=K;i++){
        scanf("%d",&a);
        if(a<=n)ck1 = 1;
        if(a>=n)ck2 = 1;
        w[a] = 1;
    }
    if(!ck1 || !ck2){
        printf("-1\n");
        return 0;
    }
    for(i=0;i<=1000;i++){
        if(w[i]){
            P[cnt++] = i - n;
            Ins(i-n, 1);
        }
    }
    while(head < tail){
        int x = Q[++head];
        for(i=0;i<cnt;i++){
            Ins(x + P[i], D[x+BASE] + 1);
        }
    }
    if(!D[BASE])printf("-1\n");
    else printf("%d\n",D[BASE]);
}