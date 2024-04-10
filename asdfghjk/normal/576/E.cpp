#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=500005;
struct node
{
       int col,id,fa,mxdep,tag;
}stk[2*N];
int n,m,K,q,a[N],b[N],x[N],y[N],nxt[N],g[N],fa[55][N],mxdep[55][N],tag[55][N],top,nowcol[N];
struct mode
{
       int id,col;
};
vector<mode> vct[N*5];
int find(int col,int x)
{
    return !fa[col][x]?x:find(col,fa[col][x]);
}
int Sum(int col,int x)
{
    return !fa[col][x]?0:Sum(col,fa[col][x])^tag[col][fa[col][x]];
}
void Union(int col,int x,int y)
{
     int z=Sum(col,x)^Sum(col,y),w1=tag[col][x],w2=tag[col][y];
     x=find(col,x),y=find(col,y);
     if(x==y)
     return;
     if(mxdep[col][x]>mxdep[col][y])
     swap(x,y),swap(w1,w2);
     z^=w1^w2;
     stk[++top]=(node){col,x,fa[col][x],mxdep[col][x],tag[col][x]};
     stk[++top]=(node){col,y,fa[col][y],mxdep[col][y],tag[col][y]};
     fa[col][x]=y;
     mxdep[col][y]=max(mxdep[col][y],mxdep[col][x]+1);
     tag[col][x]^=z^1;
}
void update(int o,int l,int r,int x,int y,int col,int id)
{
     if(l>=x&&r<=y)
     {
                   vct[o].push_back((mode){id,col});
                   return;
     }
     int mid=l+r>>1;
     if(x<=mid)
     update(o<<1,l,mid,x,y,col,id);
     if(y>mid)
     update(o<<1|1,mid+1,r,x,y,col,id);
}
void work(int o,int l,int r)
{
     int tp=top;
     for(int i=vct[o].size()-1;i>=0;--i)
     Union(vct[o][i].col,a[vct[o][i].id],b[vct[o][i].id]);
     vct[o].clear();
     if(l==r)
     {
             if(find(y[l],a[x[l]])!=find(y[l],b[x[l]])||(Sum(y[l],a[x[l]])^tag[y[l]][a[x[l]]])!=(Sum(y[l],b[x[l]])^tag[y[l]][b[x[l]]]))
             {
                                                                         nowcol[x[l]]=y[l];
                                                                         puts("YES");
                                                                         if(nxt[l]>l+1)
                                                                         update(1,1,q,l+1,nxt[l]-1,y[l],x[l]);
             }
             else
             {
                 puts("NO");
                 if(nxt[l]>l+1)
                 update(1,1,q,l+1,nxt[l]-1,nowcol[x[l]],x[l]);
             }
             while(top>tp)
             {
                          fa[stk[top].col][stk[top].id]=stk[top].fa;
                          mxdep[stk[top].col][stk[top].id]=stk[top].mxdep;
                          tag[stk[top].col][stk[top].id]=stk[top].tag;
                          --top;
             }
             return;
     }
     int mid=l+r>>1;
     work(o<<1,l,mid);
     work(o<<1|1,mid+1,r);
     while(top>tp)
     {
                  fa[stk[top].col][stk[top].id]=stk[top].fa;
                  mxdep[stk[top].col][stk[top].id]=stk[top].mxdep;
                  tag[stk[top].col][stk[top].id]=stk[top].tag;
                  --top;
     }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&K,&q);
    for(int i=1;i<=m;++i)
    scanf("%d%d",a+i,b+i);
    for(int i=1;i<=q;++i)
    nxt[i]=q+1;
    for(int i=1;i<=q;++i)
    {
                     scanf("%d%d",x+i,y+i);
                     if(g[x[i]])
                     nxt[g[x[i]]]=i;
                     g[x[i]]=i;
    }
    work(1,1,q);
    return 0;
}