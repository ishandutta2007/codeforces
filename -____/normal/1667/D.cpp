#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
int n,d[N];
vector<int> v[N],v0[N],v1[N];
int dfs(int u,int fa){
	int i,j,x,r;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x==fa)
			continue;
		r=dfs(x,u);
		if(r==-2)
			return -2;
		if(r)
			v1[u].push_back(x);
		else
			v0[u].push_back(x);
	}
	if(v0[u].size()>d[u]/2)
		return -2;
	if(v1[u].size()>d[u]-d[u]/2)
		return -2;
	if(v0[u].size()<d[u]/2)
		return 0;
	if(v1[u].size()<d[u]-d[u]/2)
		return 1;
	return -1;
}
vector<int> ansx,ansy;
void ps(int x,int y){
	ansx.push_back(x);
	ansy.push_back(y);
}
void ans(int u,int fa){
	int i,j,x,r,f=0;
	i=0,j=0;
	while(d[u]){
		if(d[u]&1){
			if(i==v1[u].size())
				ps(u,fa);
			else
				ans(v1[u][i],u),i++;
		}
		else{
			if(j==v0[u].size())
				ps(u,fa);
			else
				ans(v0[u][j],u),j++;
		}
		d[u]--;
	}
}
int main(){
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=1;i<=n;i++)
			d[i]=v[i].size();
		x=dfs(1,0);
		if(x==-2)
			printf("NO\n");
		else{
			printf("YES\n");
			ans(1,0);
			for(i=0;i<ansx.size();i++)
				printf("%d %d\n",ansx[i],ansy[i]);
			ansx.clear(),ansy.clear();
		}
		for(i=1;i<=n;i++)
			v[i].clear(),v0[i].clear(),v1[i].clear();
	}
	return 0;
}