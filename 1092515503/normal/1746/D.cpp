/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200100];
int fa[200100];
vector<int>v[200100];
map<int,ll>mp[200100];
ll f[200100];
ll dfs(int x,int z){
	if(v[x].empty())return 1ll*z*a[x];
	if(!z)return 0;
	if(mp[x].find(z)!=mp[x].end())return mp[x][z];
	ll res=1ll*z*a[x];
	if(!(z%v[x].size())){
		for(auto y:v[x])res+=dfs(y,z/v[x].size());
		return mp[x][z]=res;
	}
	for(auto y:v[x]){
		ll s=dfs(y,z/v[x].size()+1),t=dfs(y,z/v[x].size());
		f[y]=s-t;
		res+=t;
	}
	sort(v[x].begin(),v[x].end(),[](const int&u,const int&v){return f[u]>f[v];});
	for(int i=0;i<z%v[x].size();i++)res+=f[v[x][i]];
	return mp[x][z]=res;
}
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)v[i].clear(),mp[i].clear();
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]),v[fa[i]].push_back(i);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%lld\n",dfs(1,m));
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}