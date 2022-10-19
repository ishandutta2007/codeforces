#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int T,n,E,cnt,ord[N],dsu[N<<1],val[N<<1];
struct EDGE{int x,y,z;};
vector<int>v[N],u[N<<1];
vector<int>::iterator itf[N],itb[N];
inline int find(const int&x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
int dfn[N<<1],rev[N<<1],tot,lim,dep[N<<1],st[20][N<<2],LG[N<<2],fir[N<<1];
inline int MIN(const int&x,const int&y){return dep[x]<dep[y]?x:y;}
inline bool dfncmp(const int&x,const int&y){return dfn[x]<dfn[y];}
inline int LCA(int x,int y){
	x=fir[x],y=fir[y];if(x>y)swap(x,y);
	int k=LG[y-x+1];
	return MIN(st[k][x],st[k][y-(1<<k)+1]);
}
void dfs(int x){
	if(x<=n)dfn[x]=++tot,rev[tot]=x;
	st[0][++lim]=x,fir[x]=lim;
	for(auto y:u[x])dep[y]=dep[x]+1,dfs(y),st[0][++lim]=x;
}
void Kruskal(EDGE*e,int m){
	cnt=n,tot=lim=0;
	for(int i=1;i<=m;i++)ord[i]=i;
	sort(ord+1,ord+m+1,[&](int x,int y){return e[x].z<e[y].z;});
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1,x,y,z;i<=m;i++)
		if((x=find(e[ord[i]].x))!=(y=find(e[ord[i]].y)))
		val[z=++cnt]=e[ord[i]].z,
		u[z].push_back(x),u[z].push_back(y),
		dsu[x]=dsu[y]=dsu[z]=z;
	dfs(cnt);
	for(int i=2;i<=lim;i++)LG[i]=LG[i>>1]+1;
	for(int j=1;j<=LG[lim];j++)for(int i=1;i+(1<<j)-1<=lim;i++)
		st[j][i]=MIN(st[j-1][i],st[j-1][i+(1<<j-1)]);
	for(int i=1;i<=cnt;i++)u[i].clear();
}
int lp[N],rp[N];
int fp[N],bp[N];
int mn[N],mx[N],my[N],m;
EDGE e[N],f[N];
void mina(){
	scanf("%d%d",&n,&m),E=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),
		v[e[i].x].push_back(e[i].y),v[e[i].y].push_back(e[i].x);
	Kruskal(e,m);
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end(),dfncmp);
		itf[i]=itb[i]=lower_bound(v[i].begin(),v[i].end(),i,dfncmp);
		if(itf[i]!=v[i].begin())itf[i]--;
		fp[i]=bp[i]=dfn[i];
	}
	for(int i=1;i<=n;i++)dsu[i]=i;
	while(E<n-1){
		for(int l=1,r=1;l<=n;l=r){
			for(r=l;r<=n&&find(rev[l])==find(rev[r]);r++);
			for(int i=l;i<r;i++)lp[i]=l,rp[i]=r-1;
		}
		for(int i=1;i<=n;i++)mn[i]=0x3f3f3f3f,mx[i]=my[i]=-1;
//		for(int i=1;i<=n;i++)printf("[%d,%d]",lp[i],rp[i]);puts("");
		for(int i=1;i<=n;i++){
			while(fp[i]){
				if(find(rev[fp[i]])==find(i)){fp[i]=lp[fp[i]]-1;continue;}
				while(itf[i]!=v[i].begin()&&dfn[*itf[i]]>fp[i])itf[i]--;
				if(dfn[*itf[i]]==fp[i])fp[i]--;
				else break;
			}
			while(bp[i]<=n){
				if(find(rev[bp[i]])==find(i)){bp[i]=rp[bp[i]]+1;continue;}
				while(itb[i]!=v[i].end()&&dfn[*itb[i]]<bp[i])itb[i]++;
				if(itb[i]!=v[i].end()&&dfn[*itb[i]]==bp[i])bp[i]++;
				else break;
			}
			int z=0x3f3f3f3f,y=-1;
			if(fp[i]){
				int Z=val[LCA(rev[fp[i]],i)];
				if(Z<z)z=Z,y=rev[fp[i]];
			}
			if(bp[i]<=n){
				int Z=val[LCA(i,rev[bp[i]])];
				if(Z<z)z=Z,y=rev[bp[i]];
			}
			if(z<mn[find(i)])mn[find(i)]=z,mx[find(i)]=i,my[find(i)]=y;
		}
		for(int i=1;i<=n;i++)if(dsu[i]==i){
			int j=find(my[i]);
			if(j==i)continue;
//			printf("LINK:%d,%d:%d\n",mx[i],my[i],mn[i]);
			dsu[i]=j;
			++E,f[E].x=mx[i],f[E].y=my[i],f[E].z=mn[i];
		}
	}
	Kruskal(f,E);
	for(int i=1;i<=m;i++)printf("%d ",val[LCA(e[i].x,e[i].y)]);puts("");
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}