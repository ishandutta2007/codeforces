#include<cstdio>
int n,m,x,a[1005],ans=1000;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&x),a[x]++;
    for(int i=1;i<=n;i++) if(a[i]<ans) ans=a[i];
    printf("%d",ans);
}