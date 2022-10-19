#include<cstdio>
#include<queue>
#define ll long long
#define max(a,b) ((a)>(b))?(a):(b)
using namespace std;
queue<ll>q;
ll n,m,a[200001],b[200001],ans;
int main(){
	register int i;
    scanf("%lld%lld%lld%lld",&n,&m,&a[1],&b[1]);
    ans=a[1]+b[1];
    q.push(ans);
    printf("%lld ",ans);
    for(i=2;i<=n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        while(q.front()<=a[i]&&!q.empty()) q.pop();
        if(q.size()<=m){
            ans=max(ans,a[i]);
            ans+=b[i];
            printf("%lld\n",ans);
            q.push(ans);
        }
        else printf("-1 ");
    }
}