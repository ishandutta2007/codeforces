#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
long long a[100005][2];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",a[i]+1);
            a[i][1]+=a[i-1][1];
        }
        a[n+1][0]=0;
        long long ans=1e18;
        for(int i=n;i>0;i--){
            a[i][0]+=a[i+1][0];
            ans=min(ans,max(a[i+1][0],a[i-1][1]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}