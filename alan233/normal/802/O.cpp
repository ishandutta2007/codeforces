// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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

const int N=500005;

int a[N],b[N],n,K;

pair<ll,ll> ans;
bool check(ll S){
    ans.fir=ans.sec=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    per(i,n,1){
        pq.push(make_pair(b[i],-1));
        auto best=pq.top();
        if(S-a[i]>=best.fir){
            ans.fir+=S-a[i]-best.fir;
            ans.sec-=best.sec;
            pq.pop();
            pq.push(make_pair(S-a[i],0));
        }
    }
    return ans.sec>=K;
}

int main(){
    // freopen("world.in","r",stdin);
    // freopen("world.out","w",stdout);
    n=read(),K=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)b[i]=read();
    ll l=0,r=2e9;ll ANS=0;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid)){
            ANS=ans.fir-1ll*mid*K;
            r=mid;
        }else{
            l=mid+1;
        }
    }
    print(-ANS,'\n');
    return 0;
}