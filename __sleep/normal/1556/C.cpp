#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[1005][10],ans=0;
long long b[1005];
inline long long judge(int i,int j){
    long long l1,r1,l2,r2,x,k;
    l1=a[i-1][0];  r1=a[i][0];
    l2=a[j][0];    r2=a[j-1][0];
    if(r1<l2||r2<l1) return 0;
    x=max(l1,l2);
    for(k=0;(1<<k)<=(j-i);++k); --k;
    // if(i==1&&j==2){
        // printf("%lld %lld %lld\n",min(a[j-1][k],a[i+(1<<k)-1][k]),x,k);
    // }
    if(min(a[j-1][k],a[i+(1<<k)-1][k])<x) return 0; 
    return min(a[j-1][k],a[i+(1<<k)-1][k])-x+1-(j==i+1?1:0);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",a[i]);
        b[i]=a[i][0];
        b[i]+=a[i-1][0];
        if(!(i&1)) a[i][0]*=-1;
        a[i][0]+=a[i-1][0];
        for(int j=1;i-(1<<j)>=0;j++){
            a[i][j]=min(a[i][j-1],a[i-(1<<(j-1))][j-1]);
        }
        // printf("%lld ",a[i][0]);
    }
    // puts("");
    // printf("%lld\n",a[2][1]);
    for(int i=1;i<=n;i+=2){
        for(int j=i+1;j<=n;j+=2){
            ans+=(judge(i,j));
            // printf("%lld %lld %lld\n",i,j,judge(i,j));
        }
    }
    printf("%lld\n",ans);
    return 0;
}