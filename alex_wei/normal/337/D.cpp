#include <bits/stdc++.h> //////////////////
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>
   
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))
   
inline int read(){
    int x=0,sgn=0; char s=getchar();
    while(!isdigit(s))sgn|=s=='-',s=getchar();
    while(isdigit(s))x=x*10+s-'0',s=getchar();
    return sgn?-x:x;
}

template <class T> void cmin(T &a,T b){a=a<b?a:b;}
template <class T> void cmax(T &a,T b){a=a>b?a:b;}

const int N=1e5+5;

int n,m,d,ans,res[N],pos[N];
vint e[N],c1[N],c2[N];
vpii d1[N],d2[N];

int dn,dep[N],dfn[N],lg[N<<1],mi[N<<1][18];
int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
void dfs(int id,int f){
	mi[dfn[id]=++dn][0]=id,dep[id]=dep[f]+1;
	for(int it:e[id])if(it!=f)dfs(it,id),mi[++dn][0]=id;
}
int lca(int x,int y){
	x=dfn[x],y=dfn[y];
	if(x>y)swap(x,y);
	int d=lg[y-x+1];
	return get(mi[x][d],mi[y-(1<<d)+1][d]);
}
int dis(int x,int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}

int r,fa[N],sz[N],mx[N],vis[N],mxd[N],mxa[N];
void findr(int id,int f,int tot){
	sz[id]=mx[id]=1;
	for(int it:e[id]){
		if(it==f||vis[it])continue;
		findr(it,id,tot),sz[id]+=sz[it];
		cmax(mx[id],sz[it]);
	}
	cmax(mx[id],tot-sz[id]);
	if(mx[id]<mx[r])r=id;
}
void findd(int id,int f,int anc,int d){
	mxd[id]=1,d1[anc].pb(d,id);
	if(fa[anc])d2[anc].pb(dis(fa[anc],id),id),cmax(mxa[anc],dis(fa[anc],id));
	for(int it:e[id]){
		if(it==f||vis[it])continue;
		findd(it,id,anc,d+1),cmax(mxd[id],mxd[it]+1);
	}
}
void divide(int id){
	vis[id]=1,findd(id,0,id,0);
	c1[id].resize(mxd[id]+1),c2[id].resize(mxa[id]+1);
	for(int it:e[id]){
		if(vis[it])continue;
		r=0,findr(it,id,sz[it]);
		fa[r]=id,divide(r);
	}
}
int main(){
	cin>>n>>m>>d,mx[0]=n;
	for(int i=1;i<=m;i++)cin>>pos[i];
	for(int i=1;i<n;i++){
		int a,b; cin>>a>>b;
		e[a].pb(b),e[b].pb(a);
	}
	dfs(1,0);
	for(int i=2;i<=n<<1;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=lg[n]+1;i++)
		for(int j=1;j+(1<<i)-1<=dn;j++)
			mi[j][i]=get(mi[j][i-1],mi[j+(1<<i-1)][i-1]);
//		for(int j=1;j<=n;j++)
//			cout<<"dis "<<i<<" "<<j<<" "<<dis(i,j)<<endl;
	findr(1,0,n),divide(r);
//	for(int i=1;i<=n;i++)cerr<<i<<" "<<fa[i]<<endl;
	for(int i=1;i<=m;i++){
		int p=pos[i],d1;
		for(int u=p;u;u=fa[u]){
			if(d>=(d1=dis(p,u)))c1[u][min(mxd[u],d-d1)]++;
			if(fa[u]&&d>=(d1=dis(p,fa[u])))c2[u][min(mxa[u],d-d1)]++;
		}
	}
//	for(int i=1;i<=n;i++){
//		cerr<<"data : "<<i<<endl;
//		for(int j=0;j<=mxd[i];j++)cerr<<c1[i][j]<<" "; cout<<endl;
//		for(int j=0;j<=mxa[i];j++)cerr<<c2[i][j]<<" "; cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=mxd[i]-1;~j;j--)c1[i][j]+=c1[i][j+1];
		for(int j=mxa[i]-1;~j;j--)c2[i][j]+=c2[i][j+1];
		for(pii it:d1[i])res[it.se]+=c1[i][it.fi];
		for(pii it:d2[i])res[it.se]-=c2[i][it.fi];
	}
//	for(int i=1;i<=n;i++)cerr<<"Res "<<i<<" "<<res[i]<<" "<<mxd[i]<<" "<<mxa[i]<<endl;
	for(int i=1;i<=n;i++)if(res[i]==m)ans++;
	cout<<ans<<endl;
    return 0;
}
/*
6 1 3
3
1 5
2 3
3 4
4 5
5 6
*/