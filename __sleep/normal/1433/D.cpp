#include<cstdio>
int t,n,fa[5005],a[5005];
int ansa[5005],ansb[5005],ct;
int find(int x){
    return fa[x]==x?x:(fa[x]=find(fa[x]));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); ct=0;
        for(int i=1;i<=n;i++){
            fa[i]=i;
            scanf("%d",a+i);
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]!=a[j]&&find(i)!=find(j)){
                    fa[fa[i]]=fa[j];
                    ansa[++ct]=j;
                    ansb[ct]=i;
                }
            }
        }
        if(ct==n-1){
            puts("YES");
            for(int i=1;i<n;i++)
                printf("%d %d\n",ansa[i],ansb[i]);
        }
        else puts("NO");
    }
    return 0;
}