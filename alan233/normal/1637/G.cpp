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

vector<pii> ans;
priority_queue<int> pq;
int cnt[N],fail[N];
int lim,n;

void push(int u){
    cnt[u]++,pq.push(u);
    for(int i=lim;i>=u&&i>0;i>>=1){
        if(fail[i-u]){
            fail[i-u]--;
            push(i-u);
            break;
        }
    }
}
void solve(){
    n=read(),ans.clear();
    if(n==2)return puts("-1"),void();
    rep(i,0,2*n)cnt[i]=fail[i]=0;
    lim=1;while(lim<n)lim<<=1;
    rep(i,1,n)cnt[i]=1,pq.push(i);
    while(!pq.empty()){
        int u=pq.top();pq.pop();
        if(!cnt[u]||u==lim)continue;
        cnt[u]--;
        bool ok=0;
        for(int i=lim;i>=u&&i>0;i>>=1){
            if(cnt[i-u]){
                cnt[i-u]--;
                ans.pb({i-u,u});
                push(i),push(abs(2*u-i));
                ok=1;
                break;
            }
        }
        if(!ok)fail[u]++;
    }    
    print(SZ(ans),'\n');
    for(auto [u,v]:ans)print(u,' '),print(v,'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}