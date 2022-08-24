#include<stdio.h>
int n, K, Ed[1010000][2], cnt;
void Add_Edge(int a, int b){
    Ed[cnt][0]=a,Ed[cnt][1]=b;
    cnt++;
}
int main(){
    scanf("%d%d",&n,&K);
    if(n==2||n==3){
        printf("-1\n");
        return 0;
    }
    int i, j;
    if(K!=2&&K!=3){
        printf("-1\n");
        return 0;
    }
    if(K==2){
        if(n==4){
            printf("-1\n");
            return 0;
        }
        printf("%d\n",n-1);
        for(i=1;i<n;i++)printf("%d %d\n",i,i+1);
        return 0;
    }
    int m = n/2;
    for(i=2;i<=m;i++)Add_Edge(1,i);
    for(i=2;i<=m;i++)for(j=m+1;j<n;j++)Add_Edge(i,j);
    for(j=m+1;j<n;j++)Add_Edge(j,n);
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++)printf("%d %d\n",Ed[i][0],Ed[i][1]);
}