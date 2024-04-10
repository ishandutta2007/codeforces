// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((long long)(x.size()))
#define pii pair<int,int>
#define int long long
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=100005;

set<int>pos[26];
char a[N],b[N];
int n;
int ban[N];

struct fen{
    int c[N];
    void ini(int n){
        rep(i,1,n)c[i]=0;
    }
    void add(int x,int dlt){
        while(x>0){
            c[x]+=dlt;
            x^=x&-x;
        }
    }    
    int qry(int x){
        int ret=0;
        while(x<=n){
            ret+=c[x];
            x+=x&-x;
        }
        return ret;
    }
}tr;

void solve(){
    scanf("%d%s%s",&n,a+1,b+1);
    tr.ini(n);
    rep(i,0,25)pos[i].clear();
    rep(i,1,n){
        a[i]-='a';b[i]-='a';
        ban[i]=0; 
        pos[a[i]].insert(i);
    }
    ll ans=1e18,now=1,step=0;
    rep(i,1,n){
        while(ban[now])now++;
        if(a[now]<b[i]){
            ckmin(ans,step);
            break;
        }
        int minpos=1e9;
        rep(j,0,b[i]-1){
            if(SZ(pos[j])){
                int zz=*pos[j].begin();
                if(zz<minpos)minpos=zz;
            }
        }
        if(minpos!=1e9){
//            printf("When i=%d,step=%d,minpos=%d\n",i,step,minpos);
            ckmin(ans,step+minpos-i+tr.qry(minpos));
        }
        if(!SZ(pos[b[i]]))break;
        int zz=*pos[b[i]].begin();
        pos[b[i]].erase(zz);
        ban[zz]=1;
//        printf("When i=%d,remove %d\n",i,zz);
        step+=zz-i+tr.qry(zz);
        tr.add(zz,1);
    }
    if(ans>=1e12)ans=-1;
    printf("%lld\n",ans);
}

signed main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}