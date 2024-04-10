#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int MAXSIZE=10000020;
const int INF=0x3f3f3f3f;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
        bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
int readint(){
    int val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char *s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
const int maxn=21002;
const int maxm=300002;
struct edge{
    int to,cap,next;
};
struct graph{
    int n,m;
    edge e[maxm];
    int first[maxn],cur[maxn];
    void init(int n){
        this->n=n;
        memset(first,-1,(n+1)*4);
        m=1;
    }
    void addedge(int from,int to,int cap){
        e[++m]=(edge){to,cap,first[from]};
        first[from]=m;
        e[++m]=(edge){from,0,first[to]};
        first[to]=m;
    }
    int q[maxn];
    int dist[maxn];
    int t;
    bool bfs(int s){
        int l=1,r=1;
        q[1]=s;
        memset(dist,-1,(n+1)*4);
        dist[s]=0;
        while(l<=r){
            int u=q[l++];
            for(int i=first[u];i!=-1;i=e[i].next){
                int v=e[i].to;
                if ((dist[v]!=-1) || (!e[i].cap))
                    continue;
                dist[v]=dist[u]+1;
                if (t==v)
                    return true;
                q[++r]=v;
            }
        }
        return dist[t]!=-1;
    }
    int dfs(int u,int flow){
        if (u==t)
            return flow;
        for(int& i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!e[i].cap || dist[v]!=dist[u]+1)
                continue;
            int t=dfs(v,min(flow,e[i].cap));
            if (t){
                e[i].cap-=t;
                e[i^1].cap+=t;
                return t;
            }
        }
        return 0;
    }
    int ans=0;
    int dinic(int s,int t){
        this->t=t;
        ans=0;
        while(bfs(s)){
            int flow;
            memcpy(cur,first,(n+1)*4);
            while(flow=dfs(s,INF))
                ans+=flow;
        }
        return ans;
    }
}g;
struct ed{
    int u,v,d;
    bool operator <(const ed& rhs)const{
        return d<rhs.d;
    }
}a[maxm];
int n,m;
int check(int x){
    int s=2*n+1,t=2*n+2;
    g.init(t);
    for(int i=1;i<=n;i++)
        g.addedge(s,i,1),g.addedge(i+n,t,1);
    for(int i=1;i<=x;i++)
        g.addedge(a[i].u,a[i].v+n,1);
    return g.dinic(s,t);
}
int main(){
    init();
    n=readint(),m=readint();
    for(int i=1;i<=m;i++){
        int u=readint(),v=readint(),d=readint();
        a[i]=(ed){u,v,d};
    }
    sort(a+1,a+m+1);
    int l=1,r=m+1;
    while(l<r){
        int mid=(l+r)/2;
        if (check(mid)==n)
            r=mid;
        else l=mid+1;
    }
    printf("%d",l==m+1?-1:a[l].d);
}