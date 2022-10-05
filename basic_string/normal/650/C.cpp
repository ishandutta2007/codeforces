#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>e[N];
vector<pair<int,int> >a[N],b[N];
int d[N],g[N],q[N],f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main(){
	int id=0,i,j,k,l,n,m,h=0,t=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			scanf("%d",&k),++id,f[id]=id;
			a[i].push_back({k,id}),b[j].push_back({k,id});
		}
	}
	for(i=1;i<=n;++i){
		sort(a[i].begin(),a[i].end());
		for(j=a[i].size(),k=1;k<j;++k){
			if(a[i][k].first==a[i][k-1].first)f[getf(a[i][k].second)]=getf(a[i][k-1].second);
		}
	}
	for(i=1;i<=m;++i){
		sort(b[i].begin(),b[i].end());
		for(j=b[i].size(),k=1;k<j;++k){
			if(b[i][k].first==b[i][k-1].first)f[getf(b[i][k].second)]=getf(b[i][k-1].second);
		}
	}
	for(i=1;i<=id;++i)if(f[i]==i)e[0].push_back(i),g[i]=1;
	for(i=1;i<=n;++i){
		for(j=a[i].size(),k=1;k<j;++k){
			if(a[i][k].first!=a[i][k-1].first)l=getf(a[i][k].second),e[getf(a[i][k-1].second)].push_back(l),++g[l];
		}
	}
	for(i=1;i<=m;++i){
		for(j=b[i].size(),k=1;k<j;++k){
			if(b[i][k].first!=b[i][k-1].first)l=getf(b[i][k].second),e[getf(b[i][k-1].second)].push_back(l),++g[l];
		}
	}
	q[1]=0;
	while(h<t){
		i=q[++h];
		for(auto j:e[i]){
			--g[j];
			if(!g[j])q[++t]=j,d[j]=d[i]+1;
		}
	}
	for(i=1,id=0;i<=n;++i){
		for(j=0;j<m;++j)printf("%d ",d[getf(++id)]); 
		puts("");
	}
	return 0;
}