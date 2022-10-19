#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m,lim1,lim2;
ll res[500100];
struct qwq{
	int head[1001000],cnt,dfn[1001000],sz[1001000],bel[500100],tot,cmp,bsz[5001000];
	struct node{
		int to,next;
	}edge[2001000];
	void ae(int u,int v){
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	}
	void merge1(int x,int y){//merge x into y
		tot++,bsz[y]+=bsz[x],bsz[x]=0;
		ae(tot,bel[x]),ae(tot,bel[y]),bel[y]=tot;
	}
	void merge2(int x,int y){bsz[y]+=bsz[x],bsz[x]=0,bel[y]=++tot;}
	void dfs(int x){
		sz[x]=1,dfn[x]=++cmp;
		for(int i=head[x];i!=-1;i=edge[i].next)dfs(edge[i].to),sz[x]+=sz[edge[i].to];
	}
	void ini(){
		tot=n;
		for(int i=1;i<=n;i++)bel[i]=i,bsz[i]=1;
	}
}cam,pol;
struct st1{
	ll tag[4001000];
	void pushdown(int x){
		tag[lson]+=tag[x],tag[rson]+=tag[x],tag[x]=0;
	}
	void add(int x,int l,int r,int L,int R,int val){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){tag[x]+=val;return;}
		pushdown(x),add(lson,l,mid,L,R,val),add(rson,mid+1,r,L,R,val);
	}
	ll query(int x,int l,int r,int P){
		if(l>P||r<P)return 0;
		if(l==r)return tag[x];
		pushdown(x);
		return query(lson,l,mid,P)+query(rson,mid+1,r,P);
	}
}s1;
struct st2{
	ll tag[4001000];
	void pushdown(int x){
		if(tag[x])tag[lson]=tag[x],tag[rson]=tag[x],tag[x]=0;
	}
	void cg(int x,int l,int r,int L,int R,int val){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){tag[x]=val;return;}
		pushdown(x),cg(lson,l,mid,L,R,val),cg(rson,mid+1,r,L,R,val);
	}
	ll query(int x,int l,int r,int P){
		if(l>P||r<P)return 0;
		if(l==r)return tag[x];
		pushdown(x);
		return query(lson,l,mid,P)+query(rson,mid+1,r,P);
	}
}s2;
struct opt{
	int tp,a,b;
	vector<int>v;
}q[500100];
int main(){
	scanf("%d%d",&n,&m),memset(cam.head,-1,sizeof(cam.head)),memset(pol.head,-1,sizeof(pol.head));
	cam.ini(),pol.ini();
	for(int i=1;i<=m;i++){
		char s[10];
		scanf("%s",s);
		if(s[0]=='U')q[i].tp=1,scanf("%d%d",&q[i].b,&q[i].a),cam.merge1(q[i].a,q[i].b);
		if(s[0]=='M')q[i].tp=2,scanf("%d%d",&q[i].b,&q[i].a),pol.merge1(q[i].a,q[i].b);
		if(s[0]=='A')q[i].tp=3,scanf("%d",&q[i].a);
		if(s[0]=='Z')q[i].tp=4,scanf("%d",&q[i].a);
		if(s[0]=='Q')q[i].tp=5,scanf("%d",&q[i].a);
	}
	cam.tot++,pol.tot++;
	for(int i=1;i<=n;i++){
		if(cam.bsz[i])cam.ae(cam.tot,cam.bel[i]);
		if(pol.bsz[i])pol.ae(pol.tot,pol.bel[i]);
	}
	cam.dfs(cam.tot),pol.dfs(pol.tot);
	lim1=cam.tot,lim2=pol.tot;
	cam.ini(),pol.ini();
//	for(int i=1;i<=lim1;i++)printf("A:%d %d\n",cam.dfn[i],cam.sz[i]);
//	for(int i=1;i<=lim2;i++)printf("B:%d %d\n",pol.dfn[i],pol.sz[i]);
	for(int i=1;i<=m;i++){
		if(q[i].tp==2)pol.merge2(q[i].a,q[i].b);
		if(q[i].tp==4)s2.cg(1,1,lim2,pol.dfn[pol.bel[q[i].a]],pol.dfn[pol.bel[q[i].a]]+pol.sz[pol.bel[q[i].a]]-1,i);
		if(q[i].tp==5){
			int tmp=s2.query(1,1,lim2,pol.dfn[q[i].a]);
			q[tmp].v.push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(q[i].tp==1)cam.merge2(q[i].a,q[i].b);
		if(q[i].tp==3)s1.add(1,1,lim1,cam.dfn[cam.bel[q[i].a]],cam.dfn[cam.bel[q[i].a]]+cam.sz[cam.bel[q[i].a]]-1,cam.bsz[q[i].a]);
		if(q[i].tp==4)for(int j=0;j<q[i].v.size();j++)res[q[i].v[j]]-=s1.query(1,1,lim1,cam.dfn[q[q[i].v[j]].a]);
		if(q[i].tp==5)res[i]+=s1.query(1,1,lim1,cam.dfn[q[i].a]),printf("%lld\n",res[i]);
	}
	return 0;
}