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

int a[N],n,b[N],cnt[N];

vector<pii> adj[N];
vector<int> ans;
void dfs(int u){
    while(SZ(adj[u])){
        auto [v,id]=adj[u].back();adj[u].pop_back();
        dfs(v),ans.pb(id);
    }
}

void solve(){
    n=read();
    rep(i,1,n)cnt[i]=0;
    rep(i,1,n)a[i]=read(),b[i]=0,cnt[a[i]]++;
    int pos=0;
    rep(i,1,n){
        if(cnt[i]&1){
            if(pos){
                puts("NO");
                return;
            }
            pos=i;
        }
    }
    if(pos){
        b[(n+1)/2]=pos,cnt[pos]--;
        if(a[(n+1)/2]==pos&&!cnt[pos]){
            puts("NO");
            return;
        }
    }
    for(int i=n/2;i>=2;i--){
        if(cnt[a[i-1]])
            b[i]=b[n+1-i]=a[i-1],cnt[a[i-1]]-=2;
        else if(cnt[a[n+2-i]])
            b[i]=b[n+1-i]=a[n+2-i],cnt[a[n+2-i]]-=2;
    }
    for(int i=1,j=1;i<=n/2;i++){
        if(b[i])continue;
        while(!cnt[j])j++;
        b[i]=b[n+1-i]=j,cnt[j]-=2;
    }
    rep(i,1,n)adj[a[i]].pb({b[i],i});
    ans.clear();
    rep(i,1,n)if(SZ(adj[i])){dfs(i);break;}
    if(SZ(ans)!=n){
        puts("NO");
        // cerr << "!\n";
    }else{
        puts("YES");
        static int ANS[N];
        rep(i,0,SZ(ans)-1)ANS[ans[i]]=ans[(i+SZ(ans)-1)%SZ(ans)];
        rep(i,1,n)print(ANS[i]," \n"[i==n]);
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}