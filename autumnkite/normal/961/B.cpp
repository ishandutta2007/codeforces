#include<cstdio>
#define N 100005
int n,k,a[N],t[N],p[N],sum,ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",t+i);
    for(int i=1;i<=n;i++){
        if(t[i]) sum+=a[i],p[i]=p[i-1];
        else p[i]=p[i-1]+a[i];
    }
    for(int i=k;i<=n;i++){
        int s=p[i]-p[i-k];
        if(s>ans) ans=s;
    }
    printf("%d",ans+sum);
}