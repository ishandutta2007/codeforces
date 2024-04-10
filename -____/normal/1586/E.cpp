#include<bits/stdc++.h>
using namespace std;
const int N = 333333;
int n,m,q,f[N],a[N];
vector<int> v[N],s[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int dfs(int x,int fa,int t,int o){
	int i,y;
	s[o].push_back(x);
	if(x==t)
		return 1;
	for(i=0;i<v[x].size();i++){
		y=v[x][i];
		if(y!=fa)
			if(dfs(y,x,t,o))
				return 1;
	}
	s[o].pop_back();
	return 0;
}
int main(){
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(fnd(x)!=fnd(y)){
			v[x].push_back(y);
			v[y].push_back(x);
			f[fnd(x)]=fnd(y);
		}
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		a[x]^=1,a[y]^=1;
		dfs(x,0,y,i);
	}
	x=0;
	for(i=1;i<=n;i++)
		x+=a[i];
	if(x){
		printf("NO\n%d\n",x/2);
	}
	else{
		printf("YES\n");
		for(i=1;i<=q;i++){
			printf("%d\n",(int)s[i].size());
			for(x=0;x<s[i].size();x++)
				printf("%d ",s[i][x]);
			printf("\n");
		}
	}
	return 0;
}