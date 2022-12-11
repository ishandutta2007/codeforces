#include<cstdio>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int N=1<<21|1000,M=6e5+2;
vector<pair<int,int> > v[M];
int n,m,ls[M],cnt,per[M];
bool vis[M];
struct node{
    int val,id;
    inline bool operator <(const node &x) const{
        return val<x.val;
    }
} tr[N],lazy[N],ze={0,0},dp[M];
inline void Max(node &x,node y){
    x=max(x,y);}
inline void pushup(int id){
    if(2*id+1>2*M) return;
    Max(tr[id],tr[2*id]);
    Max(tr[id],tr[2*id+1]);
}
inline void pushdown(int id){
    if(2*id+1>2*M) return;
    if(lazy[id].val>0){
        Max(lazy[2*id],lazy[id]);
        Max(lazy[2*id+1],lazy[id]);
        Max(tr[2*id],lazy[id]);
        Max(tr[2*id+1],lazy[id]);
        lazy[id]=ze;
    }
}
void set(int id,int nl,int nr,int l,int r,const node &val){
    // printf("s:%d %d %d %d %d %d\n",id,nl,nr,l,r,val.val);
    if(l<=nl&&nr<=r){
        Max(tr[id],val);
        Max(lazy[id],val);
        return;
    }
    pushdown(id);
    int mid=(nl+nr)>>1;
    if(l<=mid) set(id*2,nl,mid,l,r,val);
    if(r>mid) set(id*2+1,mid+1,nr,l,r,val);
    pushup(id);
}
node query(int id,int nl,int nr,int l,int r){
    pushdown(id); pushup(id);
    if(l<=nl&&nr<=r) return tr[id];
    int mid=(nl+nr)>>1; node Ans=ze;
    if(l<=mid) Max(Ans,query(id*2,nl,mid,l,r));
    if(r>mid) Max(Ans,query(id*2+1,mid+1,nr,l,r));
    return Ans;
}
int main(){
    // set(1,1,M,1,2,{1,1});
    // printf("%d\n",query(1,1,M,2,2).val);
    scanf("%d%d",&n,&m);
    int x,l,r;
    while(m--){
        scanf("%d%d%d",&x,&l,&r);
        v[x].push_back({l,r});
        ls[cnt++]=l;
        ls[cnt++]=r;
    }
    sort(ls,ls+cnt);
    cnt=unique(ls,ls+cnt)-ls;
    for(int i=1;i<=n;i++){
        for(auto &p:v[i]){
            p.first=upper_bound(ls,ls+cnt,p.first)-ls;
            p.second=upper_bound(ls,ls+cnt,p.second)-ls;
        }
    }
    for(const auto &p:v[1])
        set(1,1,M,p.first,p.second,{1,1});
    dp[1]={1,1};
    for(int i=2;i<=n;i++){
        node now=ze;
        for(const auto &p:v[i])
            Max(now,query(1,1,M,p.first,p.second));
        now.val+=1;
        per[i]=now.id;
        now.id=i;
        for(const auto &p:v[i])
            set(1,1,M,p.first,p.second,now);
        dp[i]=now;
        // printf("%d %d\n",i,now.val);
    }
    auto now=query(1,1,M,1,M);
    printf("%d\n",n-now.val);
    cnt=0;
    for(int i=now.id;i;i=per[i])
        vis[i]=1;
    for(int i=1;i<=n;i++)
        if(!vis[i]) printf("%d ",i);
    if(n-dp[n].val) puts("");
    return 0;
}
/*
10 10
1 1 1
2 2 2
3 3 3
4 4 4
5 4 7
6 6 6
7 7 7
8 8 8
9 9 9
10 10 10
*/