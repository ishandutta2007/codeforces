#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,h[60],fac[100100],res;
vector<pair<int,int> >v[200100];
bool vis[200100];
vector<int>u,w;
vector<pair<int,int> >p[200100];
vector<pair<pair<int,int>,int> >q; 
void dfs(int x,int fa){
	if(x>n)w.push_back(x);else u.push_back(x);
	for(auto i:v[x])if(!vis[i.first]){
		vis[i.first]=true;
		p[x].push_back(i),p[i.first].emplace_back(x,i.second);
		dfs(i.first,x);
	}else if(i.first!=fa&&i.first<x)q.emplace_back(make_pair(i.first,x),i.second);
}
int r[200100][60][2],s[60][2],sz[200100];
bool mat[200100];
void sfd(int x,int fa){
	memset(r[x],0,sizeof(r[x]));
	r[x][0][mat[x]]=1,sz[x]=0;
	for(auto t:p[x])if(t.first!=fa){
		int y=t.first,z=t.second;
		sfd(y,x);
		for(int i=0;i<=sz[x];i++)for(int j=0;j<=sz[y];j++){
			(s[i+j][0]+=1ll*r[x][i][0]*(r[y][j][0]+r[y][j][1])%mod)%=mod;
			(s[i+j][1]+=1ll*r[x][i][1]*(r[y][j][0]+r[y][j][1])%mod)%=mod;
			(s[i+j+1][1]+=1ll*r[x][i][0]*r[y][j][0]%mod*z%mod)%=mod;
		}
		sz[x]+=sz[y]+1;
		for(int i=0;i<=sz[x];i++)for(int j=0;j<2;j++)r[x][i][j]=s[i][j],s[i][j]=0;
	}
}
void solve(){
	sort(u.begin(),u.end()),sort(w.begin(),w.end());
	if(w.size()>u.size())swap(u,w);
	if(w.size()>m/3){
		static int f[60];
		for(int i=0;i<(1<<q.size());i++){
			for(auto x:u)mat[x]=false;
			for(auto x:w)mat[x]=false;
			bool ok=true;
			int way=1;
			for(int j=0;j<q.size();j++)if(i&(1<<j)){
				if(mat[q[j].first.first]||mat[q[j].first.second]){ok=false;break;}
				mat[q[j].first.first]=mat[q[j].first.second]=true;
				way=1ll*way*q[j].second%mod;
			}
			if(!ok)continue;
			sfd(w[0],0);
//			for(int j=0;j<=sz[w[0]];j++)printf("[%d,%d]",r[w[0]][j][0],r[w[0]][j][1]);puts("");
			for(int j=0;j<=sz[w[0]];j++)
				(f[j+__builtin_popcount(i)]+=1ll*(r[w[0]][j][0]+r[w[0]][j][1])*way%mod)%=mod;
		}
		for(int i=m;i>=0;i--)if(h[i])for(int j=1;j<=m;j++)if(f[j])
			(h[i+j]+=1ll*h[i]*f[j]%mod)%=mod;
		for(int j=0;j<=m;j++)f[j]=0;
	}else{
		static int f[1<<20],g[1<<20];
		f[0]=1;
		for(auto x:u){
			for(auto i:v[x]){
				int a=lower_bound(w.begin(),w.end(),i.first)-w.begin(),b=i.second;
				for(int j=0;j<(1<<w.size());j++)if(!(j&(1<<a)))
					(g[j|(1<<a)]+=1ll*f[j]*b%mod)%=mod;
			}
			for(int j=0;j<(1<<w.size());j++)(f[j]+=g[j])%=mod,g[j]=0;
		}
		for(int i=m;i>=0;i--)if(h[i])for(int j=1;j<(1<<w.size());j++)
			(h[i+__builtin_popcount(j)]+=1ll*h[i]*f[j]%mod)%=mod;
		for(int j=0;j<(1<<w.size());j++)f[j]=0;
	}
	u.clear(),w.clear(),q.clear();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),y+=n,z=(mod+z-1)%mod,
		v[x].emplace_back(y,z),v[y].emplace_back(x,z);
	h[0]=1;
	for(int i=1;i<=(n<<1);i++)if(!vis[i])vis[i]=true,dfs(i,0),solve();
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
//	for(int i=0;i<=m;i++)printf("%d ",h[i]);puts("");
	for(int i=0;i<=m;i++)if(h[i])(res+=1ll*h[i]*fac[n-i]%mod)%=mod;
	printf("%d\n",res);
	return 0;
}