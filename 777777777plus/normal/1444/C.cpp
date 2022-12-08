#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 1e6+5;

struct e{
	int p,x,y;
	friend bool operator < (e a,e b){
		if(a.p!=b.p)return a.p<b.p;
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	}
};

int n,m,k,c[N],fa[N];
int col[N];
bool flag[N];
vector<e> G[N],G1[N];
vector<int> g[N];
int fanow;
stack<pair<int*,int>> stk;
int rnk[N],colc[N];

void dfs(int x){
	fa[x]=fanow;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(col[y]==-1){
			col[y]=col[x]^1;
			rnk[y]=1;
			dfs(y);
		}
		else if(col[x]==col[y]){
			flag[c[x]]=1;
		}
	}
}
bool www=0;

void dfs1(int x){
	for(int i=0;i<G1[x].size();++i){
		e y=G1[x][i];
		if(colc[y.p]==-1){
			colc[y.p]=colc[x]^(col[y.x]==col[y.y]);
			dfs1(y.p);
		}
		else if(colc[y.p]!=(colc[x]^(col[y.x]==col[y.y]))){
			www=1;
		}
	}
}

int main(){
	memset(col,-1,sizeof(col));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		if(c[x]>c[y])swap(x,y);
		G[c[x]].push_back({c[y],x,y});
	}
	for(int i=1;i<=k;++i)sort(G[i].begin(),G[i].end());
	for(int i=1;i<=k;++i){
		for(int j=0;j<G[i].size();++j){
			e x=G[i][j];
			if(x.p!=i)break;
			g[x.x].push_back(x.y);
			g[x.y].push_back(x.x);
		}
	}
	int totfa=0;
	for(int i=1;i<=n;++i)
	if(col[i]==-1){
		col[i]=0;
		rnk[i]=0;
		fanow=i;
		dfs(i);
	}
	memset(colc,-1,sizeof(colc));
	ll ans=1ll*k*(k-1)/2,totflag=0;
	for(int i=1;i<=k;++i)if(flag[i])totflag++;
	for(int i=1;i<=k;++i){
		if(flag[i]){
			ans-=k-i;
			totflag--;
			continue;
		}
		ans-=totflag;
		for(int j=0,r=0;j<G[i].size();j=++r)
		if(G[i][j].p!=i){
			e x=G[i][j];
			while(r+1<G[i].size()&&G[i][r+1].p==x.p)r++;
			if(flag[x.p])continue;
			static bool use[N][2];
			static int q[N];
			int cc=0;
			for(int t=j;t<=r;++t){
				x=G[i][t];
				int x1=fa[x.x],y1=fa[x.y];
				G1[x1].push_back({y1,x.x,x.y});
				G1[y1].push_back({x1,x.x,x.y});
				q[++cc]=x1;
				q[++cc]=y1;
			}
			www=0;
			for(int i=1;i<=cc;++i)
			if(colc[q[i]]==-1){
				colc[q[i]]=0;
				dfs1(q[i]);
			}
			while(cc){
				int x=q[cc];
				G1[x].clear();
				colc[x]=-1;
				--cc;
			}
			if(www)ans--;
		}
	}
	cout<<ans<<endl;
}