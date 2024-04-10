#include<cstdio>
const int N=300005;
int n,t,a[N];
long long ans=0;
int main(){
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            if(i&&1ll*a[i]*a[i-1]>ans) ans=1ll*a[i]*a[i-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}