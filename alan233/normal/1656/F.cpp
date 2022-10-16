// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=200005;
const ll inf=1e10;

ll a[N],b[N];
int n;

int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

vector<int> adj[N];
bool vis[N];
ll mem[N],to[N];
int who[N];
ll check(int id){
    if(vis[id])return mem[id];
    vis[id]=1;
    ll t=-a[id],ans=0;
    rep(i,1,n)f[i]=i;
    int comp=n;
    // printf("check id=%d,t=%lld\n",id,t);
    
    int debug=0;

    while(comp>1){
        // multiset<pii> S;
        pii min1=make_pair(inf,inf),min2=make_pair(inf,inf);
        pii max1=make_pair(-inf,-inf),max2=make_pair(-inf,-inf);
        bool ok=0;
        rep(i,1,n)adj[i].clear();
        /*
        printf("current:\n");
        rep(i,1,n)printf("group[%d]=%d, ",i,find(i));puts("");
        system("pause");
        if(++debug>=5){
            break;
        }
        */
        rep(i,1,n){
            adj[find(i)].pb(i);
            pii now=make_pair(a[i],find(i));
            if(now<min1)min2=min1,min1=now;
            else if(now<min2)min2=now;
            if(now>max1)max2=max1,max1=now;
            else if(now>max2)max2=now;
        }
        rep(i,1,n){
            if(find(i)==i){
                to[i]=1e18,who[i]=0;
                // for(auto it:adj[i])S.erase({a[it],it});
                for(auto j:adj[i]){
                    if(a[j]+t>0){
                        /*
                        auto it=S.begin();
                        ll val=a[j]*(it->fir)+t*(a[j]+(it->fir));
                        // printf("when j=%d,it=%d\n",j,it->fir);
                        if(val<to[i])
                            to[i]=val,who[i]=it->sec;
                        */
                        pii qaq=min1.sec==find(i)?min2:min1;
                        ll val=a[j]*qaq.fir+t*(a[j]+qaq.fir);
                        if(val<to[i])
                            to[i]=val,who[i]=qaq.sec;
                    }else{
                        /*
                        auto it=--S.end();
                        ll val=a[j]*(it->fir)+t*(a[j]+(it->fir));
                        // printf("when j=%d,it=%d\n",j,it->fir);
                        if(val<to[i])
                            to[i]=val,who[i]=it->sec;
                        */
                        pii qaq=max1.sec==find(i)?max2:max1;
                        ll val=a[j]*qaq.fir+t*(a[j]+qaq.fir);
                        if(val<to[i])
                            to[i]=val,who[i]=qaq.sec;
                    }
                }
                // printf("here group(i=%d), to=%lld,who=%d\n",i,to[i],who[i]);
                // for(auto it:adj[i])S.insert({a[it],it});
            }
        }
        rep(i,1,n){
            if(find(i)==i){
                if(to[i]!=1e18&&find(who[i])!=find(i)){
                    ans+=to[i],f[find(who[i])]=find(i);
                    comp--;
                }
            }
        }
    }
    // printf("ans=%lld\n",ans);
    return mem[id]=ans;
}

void solve(){
    n=read();
    bool same=1;
    rep(i,1,n)a[i]=read(),same&=a[i]==a[1];
    if(same){
        if(a[1]==0)puts("0");
        else puts("INF");
        return;
    }
    sort(a+1,a+n+1,greater<ll>()),a[0]=inf,a[n+1]=-inf;
    rep(i,0,n+1)vis[i]=0;

    // rep(i,0,n+1){
    //     check(i);
    // }
    // return;

    int l=0,r=n+1;
    while(l+20<r){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        if(check(mid1)<check(mid2))l=mid1;
        else r=mid2;
    }
    // printf("here l=%d,r=%d\n",l,r);

    ll t=-6e18;int pos=0;
    rep(i,l,r){
        ll tmp=check(i);
        if(tmp>t||(tmp==t&&(1<=i&&i<=n)))t=tmp,pos=i;
    }
    if(pos==0||pos==n+1)puts("INF");
    else printf("%lld\n",t);
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}