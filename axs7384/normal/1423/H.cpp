#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
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
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
const int maxn=100002;
const int maxm=500002;
struct ufs{
    int rk[maxn],fa[maxn],sz[maxn];
    pair<int,int> stk[maxm*2]; //0 :rk[second]++,>0:merge(x,y)
    int tp;
    void init(int n){
        for(int i=1;i<=n;i++)
            fa[i]=i,sz[i]=1;
    }
    int getf(int x){
        while(x!=fa[x])
            x=fa[x];
        return x;
    }
    void mer(int x,int y){
        x=getf(x),y=getf(y);
        if (x==y)
            return;
        if (rk[x]>rk[y])
            swap(x,y);
        stk[++tp]=make_pair(x,y);
        fa[x]=y;
        sz[y]+=sz[x];
        if (rk[x]==rk[y]){
            rk[y]++;
            stk[++tp]=make_pair(0,y);
        }
    }
    int getver(){
        return tp;
    }
    void roolback(int p){
        while(tp!=p){
            if (stk[tp].first)
                sz[stk[tp].second]-=sz[stk[tp].first],fa[stk[tp].first]=stk[tp].first;
            else rk[stk[tp].second]--;
            tp--;
        }
    }
}s;
struct edge{
    int u,v;
    bool operator <(const edge& rhs)const{
        return u==rhs.u?v<rhs.v:u<rhs.u;
    }
};
struct segtree{
    int n;
    vector<edge> t[(1<<20)+3];
    int ul,ur;
    edge v;
    void update(int o,int l,int r){
        if (ul<=l && ur>=r){
            t[o].push_back(v);
            return;
        }
        int mid=(l+r)/2;
        if (ul<=mid)
            update(o*2,l,mid);
        if (ur>mid)
            update(o*2+1,mid+1,r);
    }
    void update(int l,int r,edge v){
//         printf("update %d %d %d %d\n",l,r,v.u,v.v);
        if (l>r)
            return;
        ul=l,ur=r;
        this->v=v;
        update(1,1,n);
    }
    int q[maxm];
    int ans[maxm];
    void dfs(int o,int l,int r){
        int ver=s.getver();
        for(int i=0;i<t[o].size();i++)
            s.mer(t[o][i].u,t[o][i].v);
        if (l==r)
            ans[l]=s.sz[s.getf(q[l])];
        else{
            int mid=(l+r)/2;
            dfs(o*2,l,mid);
            dfs(o*2+1,mid+1,r);
        }
        s.roolback(ver);
    }
    void work(int qwq){
        s.init(qwq);
        dfs(1,1,n);
    }
}t;
//map<edge,int> mp,lst;
struct query{
    edge e;
    int l,r;
}qr[maxm];
vector<pair<edge,int> > qwq[maxm];
int main(){
    init();
    int n=readint(),q=readint(),k=readint(),tim=0,day=1,cur=0;
    for(int i=1;i<=q;i++){
        int c=readint();
        if (c==1){
            int u=readint(),v=readint();
            if (u>v)
                swap(u,v);
            edge e=(edge){u,v};
            qwq[day].push_back(make_pair(e,tim));
        }else if (c==2)
            t.q[++tim]=readint();
        else{
            day++;
            if (day>k){
                for(const auto &it:qwq[day-k])
                    qr[++cur]=(query){it.first,it.second+1,tim};
            }
        }
    }
//    printf("%d %d\n",tim,day);
    // puts("WTF");
    if (!tim)
        return 0;
    t.n=tim;
    for(int i=max(day-k+1,1);i<=day;i++)
        for(const auto &it:qwq[i])
            qr[++cur]=(query){it.first,it.second+1,tim};
    for(int i=1;i<=cur;i++)
        t.update(qr[i].l,qr[i].r,qr[i].e);
    // puts("WTF");
    t.work(n);
    for(int i=1;i<=tim;i++)
        printf("%d\n",t.ans[i]);
}