#include<cstdio>
int a[105],b[105];
int main(){
    int n,t,ans;
    scanf("%d",&t);
    a[0]=2e9;
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(a[i]==a[i-1]) b[i]=b[i-1]+1;
            else b[i]=1;
            if(ans<b[i]) ans=b[i]; 
        }
        printf("%d\n",ans);
    }
    return 0;
}