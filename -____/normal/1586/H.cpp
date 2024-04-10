#include<bits/stdc++.h>
using namespace std;
const int N = 222222;
int n,m,a[N],b[N],c[N],d[N],fa[N][22],va[N][22],e[N],s[N],t[N],f[N],g[N],ans[N][2];
vector<int> v[N],h[N];
pair<int,int> p[N],q[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void dfs(int u,int ff){
	int i,x;
	d[u]=d[ff]+1;
	fa[u][0]=ff;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=ff){
			va[x][0]=h[u][i];
			dfs(x,u);
		}
	}
}
int cal(int x,int y){
	int j,z=0;
	if(d[x]<d[y])
		swap(x,y);
	for(j=20;j>=0;j--)
		if(d[fa[x][j]]>=d[y])
			z=max(z,va[x][j]),x=fa[x][j];
	if(x==y)
		return z;
	for(j=20;j>=0;j--)
		if(fa[x][j]!=fa[y][j])
			z=max(z,max(va[x][j],va[y][j])),x=fa[x][j],y=fa[y][j];
	return max(z,max(va[x][0],va[y][0]));
}
int main(){
	int i,j,x,y,z,w,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",e+i);
	for(i=1;i<n;i++){
		scanf("%d%d%d%d",&x,&y,&z,&w);
		v[x].push_back(y);
		h[x].push_back(w);
		v[y].push_back(x);
		h[y].push_back(w);
		a[i]=x,b[i]=y,c[i]=z;
		p[i]=make_pair(z,i);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		t[i]=x,s[i]=y;
		q[i]=make_pair(x,i);
	}
	dfs(1,0);
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1],va[i][j]=max(va[i][j-1],va[fa[i][j-1]][j-1]);
	sort(p+1,p+n);
	sort(q+1,q+m+1);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=n-1,j=m;i||j;){
		if(p[i].first>=q[j].first){
			o=p[i].second;
			x=fnd(a[o]),y=fnd(b[o]);//cout<<x<<y<<endl;
			if(e[x]<e[y])
				swap(x,y);
			if(e[x]==e[y])
				g[x]=max(max(g[x],g[y]),cal(x,y));
			f[y]=x;
			i--;
		}
		else{
			o=q[j].second;
			x=s[o];
			y=fnd(x);//cout<<o<<x<<y<<endl;
			ans[o][0]=e[y];
			ans[o][1]=max(g[y],cal(x,y));
			j--;
		}
	}
	for(i=1;i<=m;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}