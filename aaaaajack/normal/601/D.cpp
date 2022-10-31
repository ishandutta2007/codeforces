#include<cstdio>
#include<utility>
#include<vector>
#include<set>
#define Q 1000000007
#define N 300100
#define F first
#define S second
#define mp make_pair
using namespace std;
int val[N],f[N];
char s[N];
vector<int> g[N]; 
typedef pair<int,int> pii;
set<pii> st[N];
int mul[N][2],add[N][2];
const int C[2]={514,55688};
int qp(int x,int p){
	int r=1;
	while(p){
		if(p&1) r=1LL*r*x%Q;
		p>>=1;
		x=1LL*x*x%Q;
	}
	return r;
}
int inv(int a){
	return qp(a,Q-2);
}
void DFS(int u,int p){
	int mx=-1;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==p) continue;
		DFS(g[u][i],u);
		if(mx==-1||st[f[g[u][i]]].size()>st[mx].size()) mx=f[g[u][i]];
	}
	if(mx==-1){
		f[u]=u;
		mul[u][0]=mul[u][1]=1;
	}
	else{
		f[u]=mx;
	}
	int im[2],zv[2];
	for(int i=0;i<2;i++){
		im[i]=inv(mul[f[u]][i]);
		zv[i]=1LL*(Q-add[f[u]][i])*im[i]%Q;
	}
	st[f[u]].insert(mp(zv[0],zv[1]));
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==p||f[g[u][i]]==mx) continue;
		int s=f[g[u][i]],rv[2];
		for(auto x:st[s]){
			rv[0]=((1LL*x.F*mul[s][0]+add[s][0])%Q+Q-add[f[u]][0])*im[0]%Q;
			rv[1]=((1LL*x.S*mul[s][1]+add[s][1])%Q+Q-add[f[u]][1])*im[1]%Q;
			st[f[u]].insert(mp(rv[0],rv[1]));
		}
	}
	for(int i=0;i<2;i++){
		add[f[u]][i]=(1LL*add[f[u]][i]*C[i]+s[u])%Q;
		mul[f[u]][i]=(1LL*mul[f[u]][i]*C[i])%Q;
	}
	val[u]+=st[f[u]].size();
}
int main(){
	int n,x,y,cnt=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	scanf("%s",s+1);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0);
	for(int i=1;i<=n;i++){
		if(val[i]>ans){
			ans=val[i];
			cnt=1;
		}
		else if(val[i]==ans) cnt++;
	}
	printf("%d\n%d\n",ans,cnt);
	return 0;
}