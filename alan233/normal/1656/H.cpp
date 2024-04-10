// Author: wlzhouzhuan
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

inline __int128 read(){
    __int128 x=0,f=0;char ch=getchar();
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

const int N=1005;

__int128 a[N],b[N];

struct SMT1{
    #define ls (u<<1)
    #define rs (u<<1|1)
    __int128 val[N<<2];
    void build(int u,int l,int r,__int128 num){
        if(l==r){
            val[u]=num/__gcd(num,b[l]);
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid,num),build(rs,mid+1,r,num);
        val[u]=__gcd(val[ls],val[rs]);
    }
    void update(int u,int l,int r,int pos){
        if(l==r)return val[u]=0,void();
        int mid=l+r>>1;
        if(pos<=mid)update(ls,l,mid,pos);
        else update(rs,mid+1,r,pos);
        val[u]=__gcd(val[ls],val[rs]);
    }
}ta[N];
struct SMT2{
    #define ls (u<<1)
    #define rs (u<<1|1)
    __int128 val[N<<2];
    void build(int u,int l,int r,__int128 num){
        if(l==r){
            val[u]=num/__gcd(num,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid,num),build(rs,mid+1,r,num);
        val[u]=__gcd(val[ls],val[rs]);
    }
    void update(int u,int l,int r,int pos){
        if(l==r)return val[u]=0,void();
        int mid=l+r>>1;
        if(pos<=mid)update(ls,l,mid,pos);
        else update(rs,mid+1,r,pos);
        val[u]=__gcd(val[ls],val[rs]);
    }
}tb[N];
bool bana[N],banb[N];
int n,m;

void solve(){
    n=read(),m=read();
    rep(i,1,n)a[i]=read(),bana[i]=0;
    rep(i,1,m)b[i]=read(),banb[i]=0;
    rep(i,1,n)ta[i].build(1,1,m,a[i]);
    rep(i,1,m)tb[i].build(1,1,n,b[i]);
    int cur1=n,cur2=m;
    while(1){
        bool ok=0;
        rep(i,1,n){
            if(!bana[i]&&ta[i].val[1]>1){
                bana[i]=1,cur1--;
                rep(j,1,m)
                    if(!banb[j])
                        tb[j].update(1,1,n,i);
                ok=1;
                break;
            }
        }
        rep(j,1,m){
            if(!banb[j]&&tb[j].val[1]>1){
                banb[j]=1,cur2--;
                rep(i,1,n)
                    if(!bana[i])
                        ta[i].update(1,1,m,j);
                ok=1;
                break;
            }
        }
        if(ok){
            if(!cur1||!cur2){
                puts("NO");
                return;
            }
        }else{
            break;
        }
    }
    puts("YES");
    printf("%d %d\n",cur1,cur2);
    rep(i,1,n)if(!bana[i])print(a[i],' ');puts("");
    rep(i,1,m)if(!banb[i])print(b[i],' ');puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}