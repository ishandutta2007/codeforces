#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
#define Q 1000000007
using namespace std;
int pf[N],prime[N],pcnt=0;
int fac[2*N];
bool isprime[N];
int qpow(int x,int n){
    int a=x,r=1;
    while(n){
        if(n&1) r=1LL*r*a%Q;
        a=1LL*a*a%Q;
        n>>=1;
    }
    return r;
}
inline int inv(int x){
    return qpow(x,Q-2);
}
int sol(int f,int n){
    if(f>n) return 0;
    n-=f;
    int a=1LL*fac[n]*fac[f-1]%Q;
    return 1LL*inv(a)*fac[n+f-1]%Q;
}
int main(){
    int i,j,n,f,q,t,p,ans;
    vector<int> v,s;
    memset(isprime,-1,sizeof(isprime));
    for(i=2;i<N;i++){
        if(isprime[i]){
            prime[pcnt++]=i;
            pf[i]=i;
        }
        for(j=0;j<pcnt&&i*prime[j]<N;j++){
            isprime[i*prime[j]]=false;
            pf[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    fac[0]=1;
    for(i=1;i<2*N;i++){
        fac[i]=1LL*fac[i-1]*i%Q;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&n,&f);
        v.clear();
        s.clear();
        ans=sol(f,n);
        v.push_back(n);
        s.push_back(0);
        t=1;
        while(n>1){
            p=pf[n];
            while(n%p==0) n/=p;
            for(i=0;i<t;i++){
                v.push_back(v[i]/p);
                s.push_back(1-s[i]);
                if(s[i]) ans=(ans+sol(f,v[i]/p))%Q;
                else ans=(ans+Q-sol(f,v[i]/p))%Q;
            }
            t<<=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}