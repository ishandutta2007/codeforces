#include<bits/stdc++.h>
using namespace std;
const int N=5009,P=998244353;
int n,m,md[N],f[N][N],tf[N];
basic_string<int>g[N];
void upd(int&x,int y){if(x+=y,x>=P)x-=P;}
void dfs(int x,int y){
	f[x][0]=1;
	int j,k,l;
	for(int i:g[x])if(i!=y){
		dfs(i,x),memset(tf,0,m*4+4);
		for(j=min(md[x],m);~j;--j)for(k=min(m,md[i]);~k;--k)
		if(l=f[x][j]*1ll*f[i][k]%P,upd(tf[j],l),j+k<m)upd(tf[max(j,k+1)],l);
		memcpy(f[x],tf,m*4+4),md[x]=max(md[x],md[i]+1);
	}
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	for(dfs(1,0),i=j=0;i<=m;++i)upd(j,f[1][i]);
	printf("%d",j);
	return 0;
}