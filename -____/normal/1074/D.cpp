//CF1074D
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
const int N = 444444;
int n,f[N],g[N],p[N];
map<int,int> M;
vector<int> v[N],h[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void dfs(int u,int P){
	p[u]=P;
	int i=v[u].size();
	while(i--){
		dfs(v[u][i],P^h[u][i]);
	}
}
int main()
{
	int q,l=0,i,x,y,z,X,Y;
	for(i=0;i<N;i=i+1)
		f[i]=i,g[i]=1,p[i]=0;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&z,&x,&y);
		x^=l,y^=l;
		if(x>y)
			swap(x,y);
		//cout<<x<<y<<endl;
		y++;
		if(M.find(x)==M.end())
			M[x]=++n;
		if(M.find(y)==M.end())
			M[y]=++n;
		x=M[x],y=M[y];
		X=fnd(x),Y=fnd(y);
		if(z==1){
			scanf("%d",&z);
			z^=l;
			//cout<<z<<endl;
			if(X==Y)
				continue;
			if(g[X]<g[Y])
				swap(x,y),swap(X,Y);
			v[x].push_back(Y);
			h[x].push_back(p[y]^z);
			dfs(Y,p[x]^p[y]^z);
			f[Y]=X;
			g[X]+=g[Y];
		}
		else{
			if(X!=Y)
				l=-1;
			else
				l=p[x]^p[y];
			cout<<l<<endl;
			if(l==-1)
				l=1;
		}
	}
	return 0;
}