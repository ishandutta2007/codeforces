#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],f[200100],in[200100],g[200100],mx;
vector<int>v[200100],u[200100];
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y),u[y].push_back(x),in[x]++;
	}
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		sort(v[x].begin(),v[x].end(),[](int i,int j){return f[i]<f[j];});
		for(auto i:v[x])if(f[x]==f[i])f[x]++;
		for(auto y:u[x])if(!--in[y])q.push(y);
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	for(int i=1;i<=n;i++)g[f[i]]^=a[i],mx=max(mx,f[i]);
	while(mx>=0&&!g[mx])mx--;
	if(mx==-1){puts("LOSE");return 0;}
	puts("WIN");
	for(int i=1;i<=n;i++){
		if(f[i]!=mx)continue;
		if((a[i]^g[mx])>=a[i])continue;
		a[i]^=g[mx],g[mx]=0;
		for(auto j:v[i])a[j]^=g[f[j]],g[f[j]]=0;
		break;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}