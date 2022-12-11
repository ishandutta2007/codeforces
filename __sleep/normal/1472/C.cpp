#include<cstdio>
int n,a[200005],t,ans,f[200005];
inline int max(int x,int y){return x>y?x:y;}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=n-1;i>=0;i--){
            if(i+a[i]<n) f[i]=f[i+a[i]]+a[i];
            else f[i]=a[i];
            ans=max(f[i],ans);
        }
        printf("%d\n",ans);    
    }
    return 0;
}