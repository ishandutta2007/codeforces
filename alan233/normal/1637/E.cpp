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

const int N=300005;

vector<int> buc[N],adj[N];
int diff[N],len,a[N],n,m;

void solve(){
    n=read(),m=read();
    unordered_map<int,int> cnt;
    unordered_map<int,int> vis;
    unordered_map<int,int> ID;int IDcnt=0;
    for(int i=1;i<=n;i++){
        adj[i].clear(),adj[i].shrink_to_fit();
        a[i]=read();
        if(!ID.count(a[i]))ID[a[i]]=++IDcnt;
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)buc[i].clear(),buc[i].shrink_to_fit();
    len=0;
    for(int i=1;i<=n;i++){
        if(!vis[a[i]]){
            int t=cnt[a[i]];
            if(!SZ(buc[t]))diff[++len]=t;
            buc[t].pb(a[i]);
            vis[a[i]]=1;
        }
    }
    sort(diff+1,diff+len+1);

    // printf("len=%d\n",len);rep(i,1,len)printf("diff[%d]=%d,",i,diff[i]);puts("");

    for(int i=1;i<=len;i++)sort(buc[diff[i]].begin(),buc[diff[i]].end(),greater<int>());
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        adj[ID[x]].pb(y);
        adj[ID[y]].pb(x);
    }
    ll ans=0;
    for(auto _:ID){
        int x=_.fir,idx=_.sec;
        sort(adj[idx].begin(),adj[idx].end(),[&](int x,int y){
            return cnt[x]!=cnt[y]?cnt[x]<cnt[y]:x>y;
        });
        int j=0;
        for(int i=1;i<=len;i++){
            while(j<SZ(adj[idx])&&cnt[adj[idx][j]]<diff[i])j++;
            int k=0;
            while(k<SZ(buc[diff[i]])&&j<SZ(adj[idx])&&adj[idx][j]==buc[diff[i]][k])j++,k++;
            if(k<SZ(buc[diff[i]])&&buc[diff[i]][k]==x)k++;
            while(k<SZ(buc[diff[i]])&&j<SZ(adj[idx])&&adj[idx][j]==buc[diff[i]][k])j++,k++;
            if(k<SZ(buc[diff[i]])){
                // printf("x=%d,y=%d,cnt1=%d,cnt2=%d\n",x,buc[diff[i]][k],cnt[x],diff[i]);
                ckmax(ans,1ll*(cnt[x]+diff[i])*(x+buc[diff[i]][k]));
            }
        }
    }
    print(ans,'\n');
}

int main(){
    // freopen("1.in","r",stdin);
    int T=read();
    while(T--)solve();
    return 0;
}