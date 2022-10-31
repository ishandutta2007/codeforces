#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100100
#define M 200100
using namespace std;
vector<int> lowx[N<<2],upx[N<<2],lowy[N<<2],upy[N<<2];
vector<int> gx[N],gy[N],*g,*low,*up;
bool ans[M];
int qlx[M],qux[M],qly[M],quy[M];
int sz;
void build(int u,int l,int r){
	if(l+1==r){
		sort(g[l].begin(),g[l].end());
		for(int i=0;i<g[l].size();i++){
			low[u].push_back(g[l][i]);
			up[u].push_back(g[l][i]);
		}
		low[u].push_back(sz+1);
		up[u].push_back(sz+1);
	}
	else{
		int m=(l+r)/2,i,j;
		build(u*2,l,m);
		build(u*2+1,m,r);
		for(i=0,j=0;low[u*2][i]<=sz&&low[u*2+1][j]<=sz;){
			low[u].push_back(min(low[u*2][i],low[u*2+1][j]));
			up[u].push_back(max(up[u*2][i],up[u*2+1][j]));
			while(low[u*2][i]<=low[u].back()) i++;
			while(low[u*2+1][j]<=low[u].back()) j++;
		}
		low[u].push_back(sz+1);
		up[u].push_back(sz+1);
	}
}
int qry(int u,int l,int r,int ql,int qr,int x){
	if(l==ql&&r==qr){
		int k=lower_bound(low[u].begin(),low[u].end(),x)-low[u].begin();
		return up[u][k];
	}
	else{
		int m=(l+r)/2;
		if(qr<=m){
			return qry(u*2,l,m,ql,qr,x);
		}
		else if(ql>=m){
			return qry(u*2+1,m,r,ql,qr,x);
		}
		else{
			return max(qry(u*2,l,m,ql,m,x),qry(u*2+1,m,r,m,qr,x));
		}
	}
}
int main(){
	int n,m,k,q,x,y,i;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	while(k--){
		scanf("%d%d",&x,&y);
		gx[x].push_back(y);
		gy[y].push_back(x);
	}
	for(i=0;i<q;i++){
		scanf("%d%d%d%d",&qlx[i],&qly[i],&qux[i],&quy[i]);
	}
	g=gx;
	low=lowx;
	up=upx;
	sz=m;
	build(1,1,n+1);
	for(i=0;i<q;i++){
		if(qry(1,1,n+1,qlx[i],qux[i]+1,qly[i])<=quy[i]){
			ans[i]=true;
		}
	}
	g=gy;
	low=lowy;
	up=upy;
	sz=n;
	build(1,1,m+1);
	for(i=0;i<q;i++){
		if(qry(1,1,m+1,qly[i],quy[i]+1,qlx[i])<=qux[i]){
			ans[i]=true;
		}
	}
	for(i=0;i<q;i++){
		if(ans[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}