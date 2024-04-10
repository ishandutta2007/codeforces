#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005,P=1000000007;
long long qpow(long long a,long long b){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
    }
    return ans;
}
int main(){
    int t,n;
    vector<long long> fact(N);
    vector<long long> inv(N);
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%P;
    inv[N-1]=qpow(fact[N-1],P-2);
    for(int i=N-2;i>=0;--i)
        inv[i]=inv[i+1]*(i+1)%P;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> a(n+2),p(n+2);
        vector<bool> vis(n+2,0);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            p[a[i]]=i;
        }
        int l=p[0],r=p[0],cnt=1,now=1,nxt=1;
        vis[1]=1;
        long long ans=1;
        while(l!=0||r!=n-1){
            int len;
            if(p[nxt]<l){
                for(int i=l-1;i>=p[nxt];i--)
                    vis[a[i]]=1;
                l=p[nxt];
            }
            else{
                for(int i=r+1;i<=p[nxt];i++)
                    vis[a[i]]=1;
                r=p[nxt];
            }
            while(vis[nxt]) ++nxt;
            ++cnt;
            len=r-l-now;
            // printf("%d %d %d %d\n",len,nxt,now,nxt-now-1);
            ans=ans*fact[len]%P*inv[len-(nxt-now-1)]%P;
            now=nxt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}