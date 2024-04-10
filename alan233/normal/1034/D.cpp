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

const int N=300005;
const int inf=1e9;

int L[N],R[N],n,K;

struct node{
    int l,r,id;
    node (int _l=0,int _r=0,int _id=0){
        l=_l,r=_r,id=_id;
    }
    friend bool operator < (const node &x,const node &y){
        return x.l!=y.l?x.l<y.l:x.r<y.r;
    }
};
set<node> S;

auto split(int pos){
    auto it=S.lower_bound(node(pos));
    if(it!=S.end()&&it->l==pos)return it;
    it--;
    int l=it->l,r=it->r,id=it->id;
    S.erase(it),S.insert(node(l,pos-1,id));
    return S.insert(node(pos,r,id)).fir;
}

vector<pii> event[N];

//  >= least
int d[N];
int check(int least){
    // printf("check least=%d\n",least);
    rep(i,1,n+1)d[i]=0;
    int j=1,cur=0,ans=0;
    rep(i,1,n){
        for(auto [pos,delta]:event[i]){
            d[pos+1]-=delta;
            if(j<=pos)cur+=delta;
        }
        while(cur>=least){
            j++;
            cur+=d[j];
        }
        // printf("When i=%d,j=%d,cur=%d\n",i,j,cur);
        ans+=j-1;
        if(ans>=K)return ans;
    }
    return ans;
}

void sol(int least){
    rep(i,1,n+1)d[i]=0;
    ll ANS=0,ans=0;
    int j=1,cur=0;
    rep(i,1,n){
        for(auto [pos,delta]:event[i]){
            d[pos+1]-=delta;
            ANS+=1ll*min(j-1,pos)*delta*(n-i+1);
            if(j<=pos)cur+=delta;
        }
        // printf("When i=%d,j=%d,cur=%d,ANS=%lld\n",i,j,cur,ANS);
        while(cur>=least){
            // printf("go! cur=%d\n",cur);
            ANS+=1ll*cur*(n-i+1);
            j++;
            cur+=d[j];
        }
        ans+=j-1;
    }
    // fprintf(stderr,"ANS=%lld,ans=%lld\n",ANS,ans);
    ANS-=(ans-K)*least;
    print(ANS,'\n');
}

int main(){
    n=read(),K=read();
    S.insert(node(0,inf+1,0));
    rep(i,1,n){
        L[i]=read(),R[i]=read()-1;
        auto itr=split(R[i]+1),it=split(L[i]);
        while(it!=itr){
            event[i].pb({it->id,-(it->r-it->l+1)});
            it=S.erase(it);
        }
        event[i].pb({i,R[i]-L[i]+1});
        S.insert(node(L[i],R[i],i));
    }
    // check(13);
    // return 0;
    int l=0,r=inf+1;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)>=K)l=mid;
        else r=mid-1;
    }
    // fprintf(stderr,"l=%d\n",l);
    sol(l);
    return 0;
}