#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct node1{int x,c;}p[N];
struct node
{
  int l,r,t,id;
  node(){}
  node(int _l,int _r,int _t,int _id){l=_l; r=_r; t=_t; id=_id;}
}q[N]; int s,block[N];
bool cmp(const node &x,const node &y)
{
  if(block[x.l]!=block[y.l]) return block[x.l] < block[y.l];
  if(block[x.r]!=block[y.r]) return block[x.r] < block[y.r];
  return x.t < y.t;
}
int n,qq,a[N],b[N]; int cnt[N]; int c[N]; int ans[N]; map<int,int>mp;
void add(int x,int cc){cnt[c[b[x]]]--; c[b[x]]+=cc; cnt[c[b[x]]]++;}
void chg(int x,int cc){add(x,-1); b[x]=cc; add(x,1);}
int main()
{
  scanf("%d%d",&n,&qq);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
  mp.clear(); sort(b+1,b+n+1); int blen=0; for(int i=1;i<=n;i++) if(!mp[b[i]]) mp[b[i]]=++blen;
  for(int i=1;i<=n;i++) a[i] = mp[a[i]];

  int q2=0,q1=0; for(int i=1;i<=qq;i++)
  {
  	int op,l,r; scanf("%d%d%d",&op,&l,&r);
  	if(op==2)
  	{
  	  if(mp[r]) r=mp[r]; else mp[r]=++blen,r=blen;
  	  q2++; p[q2].x=l; p[q2].c=r;
    }
  	else{q1++; q[q1] = node(l,r,q2,q1);}
  }
  s=(int)(ceil(pow(n,2.0/3)));
  for(int i=1;i<=n;i++) block[i] = (i-1)/s+1;
  sort(q+1,q+q1+1,cmp); int nx=1; cnt[0]=1;
  for(int i=1;i<=q1;i=nx)
  {
    while(block[q[i].l] == block[q[nx].l] && block[q[i].r] == block[q[nx].r] && nx<=q1) nx++;
    for(int j=1;j<=n;j++) cnt[j] = 0,b[j] = a[j];
    for(int j=1;j<=blen;j++) c[j] = 0; int l=1; int r=0; int t=0;
   	for(int j=i;j<nx;j++)
   	{
   	  while(t<q[j].t){t++; if(l<=p[t].x && p[t].x<=r) chg(p[t].x,p[t].c); else b[p[t].x]=p[t].c;}
   	  while(r<q[j].r){r++; add(r,1);}
   	  while(l>q[j].l){l--; add(l,1);}
   	  while(r>q[j].r){add(r,-1); r--;}
	  while(l<q[j].l){add(l,-1); l++;}
	  for(int k=1;;k++){if(!cnt[k]){ans[q[j].id]=k; break;}}
   	}
  }
  for(int i=1;i<=q1;i++) printf("%d\n",ans[i]);
  return 0;
}

/*
10 4
1 2 3 1 1 2 2 2 9 9
1 1 1
1 2 8
2 7 1
1 2 8
*/