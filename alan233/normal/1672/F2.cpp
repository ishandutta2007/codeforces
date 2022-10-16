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

const int N=200005;

vector<int> adj[N];
int deg[N];
int n,a[N],b[N];

int dot;
void topo(){
    dot=0;
    queue<int> q;
    rep(i,1,n)if(!deg[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        dot++;
        for(auto v:adj[u])
            if(--deg[v]==0)
                q.push(v);
    }
}

void solve(){
    n=read();
    rep(i,1,n)adj[i].clear(),deg[i]=0;
    int mx=0,mxwho=0;
    map<int,int> cnt;
    rep(i,1,n){
        a[i]=read();
        if(++cnt[a[i]]>mx){
            mx=cnt[a[i]];
            mxwho=a[i];
        }
    }
    rep(i,1,n)b[i]=read();
    rep(i,1,n){
        if(a[i]==mxwho||b[i]==mxwho)continue;
        adj[a[i]].pb(b[i]);
        deg[b[i]]++;
    }
    topo();
    // fprintf(stderr,"[status] %d\n",dot);
    puts(dot==n?"AC":"WA");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}