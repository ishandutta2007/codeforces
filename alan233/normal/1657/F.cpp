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

inline ll read(){
    ll x=0,f=0;char ch=getchar();
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

const int N=6*400005;
const int M=N;

vector<int> adj[400005],G[M];
int n,q;

int dad[N],dep[N];
void dfs1(int u,int fa){
    dad[u]=fa,dep[u]=dep[fa]+1;
    for(auto v:adj[u])if(v!=fa)dfs1(v,u);
}
vector<int> getpa(int u,int v){
    vector<int> k1,k2;
    while(dep[u]>dep[v])k1.pb(u),u=dad[u];
    while(dep[v]>dep[u])k2.pb(v),v=dad[v];
    while(u!=v)k1.pb(u),k2.pb(v),u=dad[u],v=dad[v];
    k1.pb(u),reverse(k2.begin(),k2.end());
    for(auto it:k2)k1.pb(it);
    return k1;
}

#define yes(i) (2*i)
#define no(i) (2*i+1)
int tot;

int dfn[N],low[N],be[N],btot,dtot;
bool instk[N];
stack<int> stk;
void tarjan(int u){
    dfn[u]=low[u]=++dtot,stk.push(u),instk[u]=1;
    for(auto v:G[u]){
        if(!dfn[v]){
            tarjan(v);
            ckmin(low[u],low[v]);
        }else if(instk[v]){
            ckmin(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int y;++btot;
        while(y=stk.top()){
            be[y]=btot,instk[y]=0,stk.pop();
            if(y==u)break;
        }
    }
}

int id[400005][26];
char s[N],ans[N];
vector<int> PA[N];
string ss[N];

int main(){
    scanf("%d%d",&n,&q);
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs1(1,0);
    tot=q;
    rep(i,1,q){
        int x,y,len;
        scanf("%d%d",&x,&y);
        scanf("%s",s),len=strlen(s);
        for(int j=0;j<len;j++)ss[i]+=s[j];
        for(int j=0;j<len;j++)s[j]-='a';
        vector<int> pa=getpa(x,y);

        // printf("getpa={");for(auto it:pa)printf("%d,",it);puts("}");
        PA[i]=pa;
        for(int j=0;j<len;j++){
            if(!id[pa[j]][s[j]])id[pa[j]][s[j]]=++tot;
            G[yes(i)].pb(yes(id[pa[j]][s[j]]));
            G[no(id[pa[j]][s[j]])].pb(no(i));
        }
        reverse(pa.begin(),pa.end());
        for(int j=0;j<len;j++){
            if(!id[pa[j]][s[j]])id[pa[j]][s[j]]=++tot;
            G[no(i)].pb(yes(id[pa[j]][s[j]]));
            G[no(id[pa[j]][s[j]])].pb(yes(i));
        }
    }
    rep(i,1,n){
        vector<int> qwq;
        rep(j,0,25)if(id[i][j])qwq.pb(id[i][j]);
        for(int j=0;j<SZ(qwq);j++){
            for(int k=j+1;k<SZ(qwq);k++){
                // if(j!=k){
                    G[yes(qwq[j])].pb(no(qwq[k]));
                    G[yes(qwq[k])].pb(no(qwq[j]));
                // }
            }
        }
    }
    rep(i,1,2*tot+1)if(!dfn[i])tarjan(i);
    rep(i,1,n)ans[i]='a';
    rep(i,1,q){
        if(be[yes(i)]==be[no(i)]){
            puts("NO");
            return 0;
        }
        if(be[yes(i)]<be[no(i)]){ //  yes(i)
            for(int j=0;j<SZ(ss[i]);j++)
                ans[PA[i][j]]=ss[i][j];
        }else{
            reverse(PA[i].begin(),PA[i].end());
            for(int j=0;j<SZ(ss[i]);j++)
                ans[PA[i][j]]=ss[i][j];
        }
    }
    puts("YES");
    rep(i,1,n){
        putchar(ans[i]);
    }
    putchar('\n');
    return 0;
}