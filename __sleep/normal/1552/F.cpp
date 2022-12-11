#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005,P=998244353;
int n,x[N];
struct node{
    int x,y,s;
    inline bool operator<(const node &s){
        return x<s.x;
    }
} p[N];
long long num[N],sum[N],ans;
int main(){
    scanf("%d",&n);
    int y,s;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",x+i,&y,&s);
        p[i]={x[i],y,s};
    }
    for(int i=1;i<=n;i++){
        int j=lower_bound(x+1,x+n+1,p[i].y)-x;
        num[i]=(sum[i-1]-sum[j-1]+1ll*(x[i]-p[i].y)+2ll*P)%P;
        sum[i]=(sum[i-1]+num[i])%P;
    }
    ans=x[n]+1;
    for(int i=1;i<=n;i++)
        if(p[i].s) ans=(ans+num[i])%P;
    printf("%lld\n",ans%P);
    return 0;
}