#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N=40000,P=1000000007;
int t,isp[N],p[N],cnt;
bool check(ll a,ll b,ll c,ll x){
    if((x-a)%b||x<a) return false;
    if((x-a)/b+1>c) return false;
    return true;
}
bool check(ll b,ll q,ll y,ll c,ll r,ll z){
    if(!check(b,q,y,c)||!check(b,q,y,c+r*(z-1))||r%q) return false;
    return true;
}
void work(){
    for(int i=2;i<N;i++){
        if(!isp[i]) p[cnt++]=i;
        for(int j=0;j<cnt&&p[j]*i<N;j++){
            isp[p[j]*i]=1;
            if(i%p[j]==0) break;
        }
    }
}
void work(int x,map<int,int>& mp){
    for(int i=0;i<cnt;i++){
        int v=p[i];
        if(v*v>x) break;
        for(;x%v==0;x/=v)
            ++mp[v];
    }
    if(x>1) ++mp[x];
}
int main(){
    scanf("%d",&t);
    work();
    while(t--){
        ll b,q,y;
        ll c,r,z;
        scanf("%lld%lld%lld%lld%lld%lld",&b,&q,&y,&c,&r,&z);
        if(!check(b,q,y,c,r,z)||r%q) goto NO;
        if(
            c+r*z>b+q*(y-1)||
            c-r<b
        ) goto INF;
        goto YES;
INF:
        puts("-1");
        continue;
NO:
        puts("0");
        continue;
YES:
        map<int,int> n,m;
        work(q,n); work(r,m);
        long long now=1;
        for(auto &v:m){
            if(n[v.first]==v.second) 
                while(v.second--) now*=v.first;
        }
        long long ans=0;
        // printf("# %d %d %d\n",r,now);
        for(int i=1;i*i<=now;i++){
            // printf("%d %d\n",tmp,i);
            if(now%i) continue;
            ans=(ans+1ll*i*i)%P;
            if(now/i!=i) ans=(ans+now*now/(1ll*i*i))%P;    
        }
        printf("%lld\n",ans%P);
    }
    return 0;
}