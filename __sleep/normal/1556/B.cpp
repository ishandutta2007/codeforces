#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int t,n,a[N],sum;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); sum=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),sum+=(a[i]&=1);
        if(sum!=n/2&&sum!=(n+1)/2){
            puts("-1");
            continue;
        }
        long long ans1=0,now=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ++now;
                ans1+=abs(2*now-1-i);
                ans2+=abs(2*now-i);
            }
        }
        if(2*now>n) ans2=1e18;
        if(2*now<n) ans1=1e18;
        printf("%lld\n",min(ans1,ans2));
    }
    return 0;
}