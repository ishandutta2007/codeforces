#include <cstdio>
using namespace std;
int n,s,a[105];
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=x*60+y;
    }
    if(a[1]>s) return printf("0 0"),0;
    a[n+1]=1000000000;
    for(int i=2;i<=n+1;i++) if(a[i]-a[i-1]>2*s+1) return printf("%d %d",(a[i-1]+s+1)/60,(a[i-1]+s+1)%60),0;
}