#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N=500010;
int inf;
int a[N],b[N];
int last[N];
int n,q;

struct E{
 int next,to,id;
}e[N];

int head[N],cnt;

void add(int u,int v,int id){
 e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].id=id;
}

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int mn[N<<2],mm[N<<2];

void pushup(int x){
 mn[x]=min(mn[ls],mn[rs]);
 mm[x]=mn[x]==mn[ls]?mm[ls]:mm[rs];
}

void ins(int x,int l,int r,int v,int w){
 if(l==r){
  mn[x]=w;
  mm[x]=l;
  return ;
 }
 if(v<=mid)ins(ls,l,mid,v,w);
 else ins(rs,mid+1,r,v,w);
 pushup(x);
}

int query(int x,int l,int r,int L,int R){
 if(l>R||L>r)return 0;
 if(L<=l&&r<=R){
  if(mn[x]<L)return mm[x];
  else return 0;
 }
 int t=query(ls,l,mid,L,R);
 if(t)return t;
 return query(rs,mid+1,r,L,R);
}

int ans[N];

int main(){
 memset(mn,62,sizeof(mn));
 inf=mn[0];
    cin>>n;
    for(int i=1;i<=n;i++)
     scanf("%d",&a[i]);
    int x,y;
    cin>>q;
    for(int i=1;i<=q;i++){
     scanf("%d%d",&x,&y);
     add(y,x,i);
 }
 for(int i=1;i<=n;i++){
  ins(1,1,n,i,last[a[i]]);
  if(last[a[i]])ins(1,1,n,last[a[i]],inf);
  last[a[i]]=i;
  for(int j=head[i];j;j=e[j].next){
   ans[e[j].id]=a[query(1,1,n,e[j].to,i)];
  }
 }
 for(int i=1;i<=q;i++){
  cout<<ans[i]<<endl;
 }
}