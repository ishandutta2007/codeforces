//CF1074F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,o,a[N],b[N],d[N],f[N][22];
vector<int> v[N];
set<LL> S;
void dfs(int u,int fa){
	int i=v[u].size(),x;
	d[u]=d[fa]+1;
	f[u][0]=fa;
	a[u]=++o;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
	b[u]=o;
}
int ff(int x,int y){
	int j;
	for(j=20;f[x][0]!=y;j=j-1)
		if(d[f[x][j]]>d[y])
			x=f[x][j];
	return x;
}
int t[N<<2],w[N<<2],e[N<<2];
void ch(int k,int x){
	t[k]+=x;
	w[k]+=x;
}
void build(int k=1,int l=1,int r=n){
	t[k]=0;
	w[k]=0;
	e[k]=r-l+1;
	if(l==r)
		return;
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
}
void modify(int L,int R,int X,int k=1,int l=1,int r=n){
	//if(k==1)
	//	cout<<L<<R<<X<<endl;
	if(L<=l&&r<=R){
		ch(k,X);
		return;
	}
	if(w[k]){
		ch(k<<1,w[k]);
		ch(k<<1|1,w[k]);
		w[k]=0;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
	t[k]=max(t[k<<1],t[k<<1|1]);
	e[k]=(t[k]==t[k<<1])*e[k<<1]+(t[k]==t[k<<1|1])*e[k<<1|1];
}
int main()
{
	int q,i,j,x,y,c,m;
	LL z;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(j=1;j<=20;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	build();
	i=0;
	while(q--){
		scanf("%d%d",&x,&y);
		if(x>y)
			swap(x,y);
		z=(LL)x<<32|y;
		if(S.find(z)==S.end()){
			S.insert(z);
			c=1;
		}
		else{
			S.erase(z);
			c=-1;
		}
		if(a[x]<=a[y]&&b[y]<=b[x]){
			modify(1,n,c);
			m=ff(y,x);
			modify(a[m],b[m],-c);
		}
		else
			modify(a[x],b[x],c);
		if(a[y]<=a[x]&&b[x]<=b[y]){
			modify(1,n,c);
			m=ff(x,y);
			modify(a[m],b[m],-c);
		}
		else
			modify(a[y],b[y],c);
		i+=c;
		if(t[1]==i)
			c=e[1];
		else
			c=0;
		cout<<c<<endl;
	}
	return 0;
}