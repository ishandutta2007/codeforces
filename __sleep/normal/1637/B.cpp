#include<cstdio>
#include<algorithm>
const int N=300005;
int n,t,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            b[i]=b[i-1]+(a[i]==0);
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans+=j-i+1+b[j]-b[i-1];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}