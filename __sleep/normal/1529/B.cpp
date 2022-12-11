#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int t,n,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        int ans=upper_bound(a,a+n,0)-a;
        if(a[0]>0) ans=1;
        int mn=1e9;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<mn) mn=a[i]-a[i-1];
            if(a[i]>0){
                if(a[i]<=mn) ans++;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}