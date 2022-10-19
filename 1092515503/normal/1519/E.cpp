#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,X[400100],Y[400100];
map<pair<ll,ll>,int>mp;
vector<int>v[400100];
vector<pair<int,int> >u;
bool vis[400100],mat[200100];
void dfs(int x,int id){
	if(vis[x])return;vis[x]=true;
	for(auto i:v[x])if(i!=id)dfs(X[i]^Y[i]^x,i);
	int las=0;
	for(auto i:v[x]){
		if(i==id||mat[i])continue;
		if(las)u.emplace_back(las,i),mat[i]=mat[las]=true,las=0;
		else las=i;
	}
	if(id&&las)u.emplace_back(las,id),mat[las]=mat[id]=true;
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b,c,d;i<=n;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ll Ux=1ll*c*b,Uy=1ll*(a+b)*d,Ug=__gcd(Ux,Uy);
		Ux/=Ug,Uy/=Ug;
		ll Vx=1ll*(c+d)*b,Vy=1ll*a*d,Vg=__gcd(Vx,Vy);
		Vx/=Vg,Vy/=Vg;
		if(mp.find(make_pair(Ux,Uy))==mp.end())mp[make_pair(Ux,Uy)]=++m;
		v[X[i]=mp[make_pair(Ux,Uy)]].push_back(i);
		if(mp.find(make_pair(Vx,Vy))==mp.end())mp[make_pair(Vx,Vy)]=++m;
		v[Y[i]=mp[make_pair(Vx,Vy)]].push_back(i);
	}
	for(int i=1;i<=m;i++)if(!vis[i])dfs(i,0);
	printf("%d\n",u.size());
	for(auto i:u)printf("%d %d\n",i.first,i.second);
	return 0;
}