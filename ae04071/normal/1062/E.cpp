#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

const int MAX=1<<17;
struct seg_tr{
    pii tr[MAX<<1];
    seg_tr(){
        for(int i=0;i<MAX+MAX;i++)tr[i]=pii(MAX,-1);
    }
    pii upd(int cur,int s,int f,int idx,int val){
        if(f<idx||s>idx)return tr[cur];
        else if(s==f)return tr[cur]=pii(val,val);
        else{
            int nx=cur<<1,md=(s+f)>>1;
            pii lv=upd(nx,s,md,idx,val),rv=upd(nx+1,md+1,f,idx,val);
            //printf("%d : %d %d, %d %d\n",cur,lv.fi,lv.se,rv.fi,rv.se);
            return tr[cur]=pii(min(lv.fi,rv.fi),max(lv.se,rv.se));
        }
    }
    pii get(int cur,int s,int f,int l,int r){
        if(f<l||s>r)return pii(MAX,-1);
        else if(l<=s&&f<=r)return tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            pii lv=get(nx,s,md,l,r),rv=get(nx+1,md+1,f,l,r);
            return pii(min(lv.fi,rv.fi),max(lv.se,rv.se));
        }
    }
}tr;
int n,m;
vector<int> adj[100001];
int dfn[100001],dn=1,tv[100001];
int ea[18][100001],de[100001];

void dfs(int cur,int p,int d){
    dfn[cur]=dn;
    tv[dn++]=cur;
    tr.upd(1,0,MAX-1,cur,dfn[cur]);

    int pp=p,a=1;
    ea[0][cur]=p;
    de[cur]=d;
    while(ea[a-1][pp]){
        pp=ea[a][cur]=ea[a-1][pp];
        a++;
    }
    for(auto&it:adj[cur])if(it!=p)dfs(it,cur,d+1);
}
int lca(int u,int v){
    if(de[u]>de[v])swap(u,v);
    int dif=de[v]-de[u];
    for(int i=0;1<<i<=dif;i++)if(dif>>i&1){
        v=ea[i][v];
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--)if(ea[i][u]!=ea[i][v]){
        u=ea[i][u]; v=ea[i][v];
    }
    return ea[0][u];
}
pii proc(int l,int r,int v){
    pii res;
    if(l==v)res=tr.get(1,0,MAX-1,v+1,r);
    else if(r==v)res=tr.get(1,0,MAX-1,l,r-1);
    else{
        pii a=tr.get(1,0,MAX-1,l,v-1), b=tr.get(1,0,MAX-1,v+1,r);
        res=pii(min(a.fi,b.fi),max(a.se,b.se));
    }
    //printf("%d %d %d : %d %d\n",l,r,v,res.fi,res.se);

    int root=lca(tv[res.fi],tv[res.se]);
    //printf("#%d %d\n",root,de[root]);
    return pii(v,de[root]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
        int p;
        scanf("%d",&p);
        adj[p].push_back(i);
    }
    dfs(1,0,0);

    //printf("#%d\n",tr.get(1,0,MAX-1,1,n).se);


    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);

        pii v=tr.get(1,0,MAX-1,l,r);
        pii a=proc(l,r,tv[v.fi]),b=proc(l,r,tv[v.se]);
        if(a.se > b.se) printf("%d %d\n",a.fi,a.se);
        else printf("%d %d\n",b.fi, b.se);
    }

    return 0;
}