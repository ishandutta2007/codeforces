#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int a[N],x,n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int l=1,r,ans=0;
        while(l<=n){
            int mn=2e9,mx=-2e9;
            for(r=l;r<=n;r++){
                mx=max(mx,a[r]);
                mn=min(mn,a[r]);
                if(mx-mn>2*x) break;
            }
            if(mx-mn<=2*x) break;
            ++ans;
            l=r;
        }
        printf("%d\n",ans);
    }
    return 0;
}