#include<cstdio>
#include<algorithm>
int n, w[101000], P[101000], cnt, Q[101000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(!P[w[i]]){
            P[w[i]] = ++cnt;
            Q[cnt] = w[i];
        }
    }
    for(i=1;i<=n;i++){
        if(w[w[i]] != w[i]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++){
        printf("%d ",P[w[i]]);
    }
    printf("\n");
    for(i=1;i<=cnt;i++)printf("%d ",Q[i]);
}