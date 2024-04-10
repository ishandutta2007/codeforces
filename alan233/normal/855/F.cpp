// Author: wlzhouzhuan
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

const int N=100005;
const int inf=1e9+5;

struct SMT{
    #define ls (u<<1)
    #define rs (u<<1|1)
    int maxx[N<<2],mcnt[N<<2],smax[N<<2];
    ll sum[N<<2],tag[N<<2];
    void pushup(int u){
        sum[u]=sum[ls]+sum[rs];
        if(maxx[ls]>maxx[rs]){
            maxx[u]=maxx[ls],mcnt[u]=mcnt[ls];
            smax[u]=max(smax[ls],maxx[rs]);
        }else if(maxx[rs]>maxx[ls]){
            maxx[u]=maxx[rs],mcnt[u]=mcnt[rs];
            smax[u]=max(smax[rs],maxx[ls]);
        }else{
            maxx[u]=maxx[ls],mcnt[u]=mcnt[ls]+mcnt[rs];
            smax[u]=max(smax[ls],smax[rs]);
        }
    }
    void pushtag(int u,int dlt){
        if(maxx[u]>dlt){
            sum[u]-=1ll*mcnt[u]*(maxx[u]-dlt);
            maxx[u]=dlt,tag[u]=dlt;
        }
    }
    void pushdown(int u){
        if(tag[u]){
            pushtag(ls,tag[u]),pushtag(rs,tag[u]);
            tag[u]=0;
        }
    }
    void build(int u,int l,int r){
        if(l==r){
            maxx[u]=inf,mcnt[u]=1,sum[u]=inf;
            return;
        }
        int mid=l+r>>1;
        build(ls,l,mid),build(rs,mid+1,r);
        pushup(u);
    }
    void update(int u,int l,int r,int ql,int qr,int val){
        if(maxx[u]<=val)return;
        if(ql<=l&&r<=qr&&smax[u]<val){
            pushtag(u,val);
            return;
        }
        pushdown(u);
        int mid=l+r>>1;
        if(ql<=mid)update(ls,l,mid,ql,qr,val);
        if(qr>mid)update(rs,mid+1,r,ql,qr,val);
        pushup(u);
    }
    void Set(int u,int l,int r,int pos,int val){
        if(l==r){
            maxx[u]=sum[u]=val,mcnt[u]=1;
            return;
        }
        pushdown(u);
        int mid=l+r>>1;
        if(pos<=mid)Set(ls,l,mid,pos,val);
        else Set(rs,mid+1,r,pos,val);
        pushup(u);
    }
    ll query(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr)return sum[u];
        pushdown(u);
        int mid=l+r>>1;ll sum=0;
        if(ql<=mid)sum+=query(ls,l,mid,ql,qr);
        if(qr>mid)sum+=query(rs,mid+1,r,ql,qr);
        return sum;
    }
}pos1,pos2,neg1,neg2;

int cnt[100005],n=1e5,q;

set<int>pos,neg;

int main(){
    rep(i,1,n)pos.insert(i),neg.insert(i);
    pos1.build(1,1,n),neg1.build(1,1,n);
    q=read();
    while(q--){
        int opt=read(),l=read(),r=read()-1;
        if(opt==1){
            int k=read();
            if(k>0){
                pos1.update(1,1,n,l,r,k),pos2.update(1,1,n,l,r,k);
                for(auto it=pos.lower_bound(l);it!=pos.end()&&*it<=r;it=pos.erase(it)){
                    if(++cnt[*it]==2){
                        pos2.Set(1,1,n,*it,pos1.query(1,1,n,*it,*it));
                        neg2.Set(1,1,n,*it,neg1.query(1,1,n,*it,*it));
                    }
                }
            }else{
                k=-k;
                neg1.update(1,1,n,l,r,k),neg2.update(1,1,n,l,r,k);
                for(auto it=neg.lower_bound(l);it!=neg.end()&&*it<=r;it=neg.erase(it)){
                    if(++cnt[*it]==2){
                        pos2.Set(1,1,n,*it,pos1.query(1,1,n,*it,*it));
                        neg2.Set(1,1,n,*it,neg1.query(1,1,n,*it,*it));
                    }
                }
            }
        }else{
            print(pos2.query(1,1,n,l,r)+neg2.query(1,1,n,l,r),'\n');
        }
    }
    return 0;
}