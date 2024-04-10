#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;

int n,m,d[N][25],f[N];
vector<int> g[N],rg[N];

void dj1(int S,int *d,vector<int> *g,vector<int> *rg){
	static priority_queue<pair<int,int>> q;
	static bool vis[N];
	for(int i=1;i<=n;++i)d[i]=1e9,vis[i]=0;
	d[S]=0;
	q.push({-d[S],S});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		if(d[x]&1)swap(g,rg);
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(d[y]>d[x]){
				d[y]=d[x]+0;
				q.push({-d[y],y});
			}
		}
		for(int i=0;i<rg[x].size();++i){
			int y=rg[x][i];
			if(d[y]>d[x]+1){
				d[y]=d[x]+1;
				q.push({-d[y],y});
			}
		}
		if(d[x]&1)swap(g,rg);
	}
}

void bfs(int S,vector<int> *g,vector<int> *rg){
	static queue<pair<int,int>> q;
	static bool vis[N][25];
	for(int i=1;i<=n;++i)
	for(int j=0;j<25;++j){
		d[i][j]=1e9;
		vis[i][j]=0;
	}
//	cout<<clock()<<endl;
	d[S][0]=0;
	q.push({S,0});
	vis[S][0]=1;
//	static int c;
	while(!q.empty()){
//		++c;
		int x=q.front().first,t=q.front().second;q.pop();
		if(t+f[x]&1)swap(g,rg);
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(t+f[x]-f[y]>=25||f[y]>=1e9)continue;
			if(vis[y][t+f[x]-f[y]])continue;
			vis[y][t+f[x]-f[y]]=1;
			d[y][t+f[x]-f[y]]=d[x][t]+1;
			q.push({y,t+f[x]-f[y]});
		}
		for(int i=0;i<rg[x].size();++i){
			int y=rg[x][i];
			if(t+1+f[x]-f[y]>=25||f[y]>=1e9)continue;
			if(vis[y][t+1+f[x]-f[y]])continue;
			vis[y][t+1+f[x]-f[y]]=1;
			d[y][t+1+f[x]-f[y]]=d[x][t]+1;
			q.push({y,t+1+f[x]-f[y]});
		}
		if(t+f[x]&1)swap(g,rg);
	}
//	cout<<c<<endl;
}

int main(){
	srand(time(NULL));
//	freopen("c.in","r",stdin);
	cin>>n>>m;
//	n=2e5;
//	m=2e5-1;
	for(int i=2,x,y;i<=m+1;++i){
		scanf("%d%d",&x,&y);
//		x=i;
//		y=(rand()<<15|rand())%(i-1)+1;
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	dj1(1,f,g,rg);
//	cout<<clock()<<endl;
	bfs(1,g,rg);
//	cout<<clock()<<endl;
	if(f[n]>=25){
		ll ans=d[n][0];
		ll t=1;
		for(int j=1;j<=f[n];++j){
			ans=(ans+t)%mod;
			t=t*2%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	ll ans=2e18;
	for(int i=0;i<25;++i){
		ll t=1,res=d[n][i];
		if(res>=1e9)continue;
		for(int j=1;j<=i+f[n];++j){
			res=res+t;
			t=t*2;
		}
		ans=min(ans,res);
	}
	cout<<ans%mod<<endl;
}