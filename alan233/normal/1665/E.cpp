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

const int N=100005;

int f[20][N],lg[N],a[N],n,q;

inline int cmp(int i,int j){
    return a[i]<=a[j]?i:j;
}
inline int rmq(int l,int r){
    int len=lg[r-l];
    return cmp(f[len][l],f[len][r-(1<<len)+1]);
}

struct node{
    int pos,l,r;
    friend bool operator < (const node&x,const node&y){
        return a[x.pos]>a[y.pos];
    }
};
void solve(){
    n=read();
    rep(i,1,n)a[i]=read(),f[0][i]=i;
    rep(j,1,19)
        rep(i,1,n-(1<<j)+1)
            f[j][i]=cmp(f[j-1][i],f[j-1][i+(1<<j-1)]);
    q=read();
    while(q--){
        int l=read(),r=read();
        vector<int> wait;
        priority_queue<node> pq;
        pq.push({rmq(l,r),l,r});
        int times=31;
        while(times--&&!pq.empty()){
            auto [pos,l,r]=pq.top();pq.pop();
            wait.pb(a[pos]);
            if(l<pos)pq.push({rmq(l,pos-1),l,pos-1});
            if(pos<r)pq.push({rmq(pos+1,r),pos+1,r});
        }
        int ans=2e9;
        rep(i,0,SZ(wait)-1)
            rep(j,i+1,SZ(wait)-1)
                ckmin(ans,wait[i]|wait[j]);
        print(ans,'\n');
    }
}

int main(){
    lg[1]=0;rep(i,2,N-1)lg[i]=lg[i>>1]+1;
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}