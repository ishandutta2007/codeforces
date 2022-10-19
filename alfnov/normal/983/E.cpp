#include<bits/stdc++.h>
#define lm 200000
using namespace std;
struct Rin{
	vector<int>vc[lm+5];
	int sm[lm*23*3+5],ls[lm*23*3+5],rs[lm*23*3+5];
	int id[lm*3+5],tot=0;
	void add(int x,int y,int l,int r,int u){
		if(l==r){
			sm[y]=sm[x]+1;
			return;
		}
		ls[y]=ls[x],rs[y]=rs[x];
		int mid=(l+r)>>1;
		if(u<=mid)add(ls[x],ls[y]=++tot,l,mid,u);
		else add(rs[x],rs[y]=++tot,mid+1,r,u);
		sm[y]=sm[ls[y]]+sm[rs[y]];
	}
	int query(int x,int y,int l,int r,int ll,int rr){
		if(l>=ll&&r<=rr)return sm[y]-sm[x];
		int mid=l+r>>1,ans=0;
		if(mid>=ll)ans+=query(ls[x],ls[y],l,mid,ll,rr);
		if(mid<rr)ans+=query(rs[x],rs[y],mid+1,r,ll,rr);
		return ans;
	}
}R;
vector<int>g[lm+5];
int dep[lm+5],sz[lm+5],fa[21][lm+5];
int bg[lm+5],en[lm+5],tt=0;
int jmp[21][lm+5];
void dfs1(int x){
	sz[x]=1,bg[x]=en[x]=++tt;
	for(auto cu:g[x]){
		dep[cu]=dep[x]+1;
		fa[0][cu]=x;
		dfs1(cu);
		sz[x]+=sz[cu];
		en[x]=en[cu];
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;--i)
		if((dep[x]-dep[y])>=(1<<i))x=fa[i][x];
	if(x==y)return x;
	for(int i=20;i>=0;--i)
		if(fa[i][x]!=fa[i][y])
			x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
inline void upd(int* x,int a){
	if(dep[*x]>dep[a])*x=a;
}
void dfs2(int x){
	for(auto cu:g[x]){
		dfs2(cu);
		upd(&jmp[0][x],jmp[0][cu]);
	}
}
int main(){
	int n,m,q;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int p;
		scanf("%d",&p);
		g[p].emplace_back(i);
	}
	dep[1]=1,dfs1(1);
	dep[n+1]=n+1;
	for(int i=0;i<=20;++i)for(int j=1;j<=n;++j)
		jmp[i][j]=n+1;
	for(int i=1;i<=20;++i)for(int j=1;j<=n;++j)
		fa[i][j]=fa[i-1][fa[i-1][j]];
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		R.vc[bg[x]].emplace_back(bg[y]);
		R.vc[bg[y]].emplace_back(bg[x]);
		int l=lca(x,y);
		upd(&jmp[0][x],l);
		upd(&jmp[0][y],l);
	}
	dfs2(1);
	for(int i=1;i<=20;++i)for(int j=1;j<=n;++j)
		jmp[i][j]=jmp[i-1][jmp[i-1][j]];
	int ls=0;
	for(int i=1;i<=n;++i){
		for(auto cu:R.vc[i]){
			int sl=++R.tot;
			R.add(ls,sl,1,n,cu);
			ls=sl;
		}
		int sl=++R.tot;
		R.sm[sl]=R.sm[ls];
		R.ls[sl]=R.ls[ls];
		R.rs[sl]=R.rs[ls];
		R.id[i]=sl;
	}
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int l=lca(x,y),ans=0;
		for(int i=20;i>=0;--i){
			if(jmp[i][x]&&dep[jmp[i][x]]<dep[x]){
				if(dep[jmp[i][x]]>dep[l])
					x=jmp[i][x],ans+=1<<i;
			}
		}
		for(int i=20;i>=0;--i){
			if(jmp[i][y]&&dep[jmp[i][y]]<dep[y]){
				if(dep[jmp[i][y]]>dep[l])
					y=jmp[i][y],ans+=1<<i;
			}
		}
		int flag=1;
		if(dep[x]<=dep[l]||dep[jmp[0][x]]<=dep[l]);
		else flag=0;
		if(dep[y]<=dep[l]||dep[jmp[0][y]]<=dep[l]);
		else flag=0;
		if(!flag){
			printf("-1\n");
			continue;
		}
		int L1=bg[x],R1=en[x];
		int L2=bg[y],R2=en[y];
		if(l!=x&&l!=y){
			if(!R.query(R.id[L1-1],R.id[R1],1,n,L2,R2))++ans;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}