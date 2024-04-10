#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[3][500100];
struct SegTree{
    int tr[9],num[9];
    friend SegTree operator*(const SegTree&u,const SegTree&v){
        SegTree w;
        for(int i=0;i<9;i++)w.tr[i]=v.tr[u.tr[i]],w.num[i]=u.num[i]+v.num[u.tr[i]];
        return w;
    }
}seg[2001000];
int val[9][3]={
{-1,-1,-1},
{-1,-1,2},
{-1,1,-1},
{0,-1,-1},
{0,0,-1},
{-1,1,1},
{0,-1,0},
{0,-1,2},
{0,0,0}
};
int dsu[6];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool merge(int x,int y){
    if(dsu[x]==-1||dsu[y]==-1)return false;
    x=find(x),y=find(y);
    if(x==y)return false;
    dsu[x]=y;return true;
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
void build(int x,int l,int r){
    if(l==r){
        for(int i=0;i<9;i++){
            for(int j=0;j<3;j++)dsu[j]=val[i][j];
            for(int j=0;j<3;j++)if(s[j][l]=='1')dsu[j+3]=j+3,seg[x].num[i]++;else dsu[j+3]=-1;
            if(merge(0,3))seg[x].num[i]--;
            if(merge(1,4))seg[x].num[i]--;
            if(merge(2,5))seg[x].num[i]--;
            if(merge(3,4))seg[x].num[i]--;
            if(merge(4,5))seg[x].num[i]--;
            for(int j=0;j<9;j++){
                bool ok=true;
                for(int k=0;k<3;k++)ok&=((val[j][k]==-1)==(dsu[k+3]==-1));
                if(!ok)continue;
                for(int u=0;u<3;u++)for(int v=u+1;v<3;v++)
                    if(val[j][u]!=-1&&val[j][v]!=-1)
                        ok&=((val[j][u]==val[j][v])==(find(u+3)==find(v+3)));
                if(ok){seg[x].tr[i]=j;break;}
            }
        }
    }else build(lson,l,mid),build(rson,mid+1,r),seg[x]=seg[lson]*seg[rson];
}
SegTree query(int x,int l,int r,int L,int R){
    if(L<=l&&r<=R)return seg[x];
    if(R<=mid)return query(lson,l,mid,L,R);
    if(L>mid)return query(rson,mid+1,r,L,R);
    return query(lson,l,mid,L,R)*query(rson,mid+1,r,L,R);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++)scanf("%s",s[i]+1);
    build(1,1,n);
    scanf("%d",&q);
    for(int i=1,l,r;i<=q;i++)scanf("%d%d",&l,&r),printf("%d\n",query(1,1,n,l,r).num[0]);
    return 0;
}