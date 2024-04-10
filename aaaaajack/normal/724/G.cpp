#include<bits/stdc++.h>
using namespace std;
const int Q=1000000007;
const int N=100100;
vector<int> g[N];
vector<long long> t[N],cyc[N];
bool vis[N];
int sz[N],rt[N],dim[N];
long long px[N],flp[N];
int add[70];
long long p2[100];
void DFS(int u, long long pre, int r){
	rt[u]=r;
	sz[u]=1;
	px[u]=pre;
	vis[u]=true;
	int tmp=0;
	long long tx=px[u];
	while(tx){
		add[tmp]+=tx&1;
		tx>>=1;
		tmp++;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]){
			DFS(v,pre^t[u][i],r);
			sz[u]+=sz[v];
		}
		else{
			cyc[r].push_back(px[u]^px[v]^t[u][i]);
		}
	}
}
long long gauss(int r){
	vector<long long> tmp,piv;
	for(int i=0;i<cyc[r].size();i++){
		for(int j=0;j<tmp.size();j++){
			if(cyc[r][i]&piv[j]) cyc[r][i]^=tmp[j];
		}
		if(cyc[r][i]){
			tmp.push_back(cyc[r][i]);
			piv.push_back(cyc[r][i]&-cyc[r][i]);
		}
	}
	dim[r]=tmp.size();
	for(int i=0;i<tmp.size();i++){
		flp[r]|=tmp[i];
	}
	long long tadd=0;
	for(int j=59;j>=0;j--){
		tadd=(tadd+tadd)%Q;
		if((flp[r]>>j)&1){
			tadd+=1LL*sz[r]*(sz[r]-1)/2%Q*p2[dim[r]-1]%Q;
		}
		else{
			tadd+=p2[dim[r]]*(sz[r]-add[j])%Q*add[j]%Q;
		}
	}
	return tadd;
}
int main(){
	p2[0]=1;
	for(int i=1;i<100;i++) p2[i]=(p2[i-1]*2)%Q;
	int n,m,x,y;
	long long k,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&x,&y,&k);
		g[x].push_back(y);
		g[y].push_back(x);
		t[x].push_back(k);
		t[y].push_back(k);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			memset(add,0,sizeof(add));
			DFS(i,0,i);
			ans+=gauss(i);
			ans%=Q;
		}
	}
	printf("%lld\n",ans);
	return 0;
}