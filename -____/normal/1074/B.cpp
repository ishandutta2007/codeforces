//CF1074B
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
const int N = 1111;
int n,a[N],b[N];
vector<int> v[N];
int dfs(int u,int fa){
	if(a[u])
		return u;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		x=dfs(x,u);
		if(x>0)
			return x;
	}
	return 0;
}
int main()
{
	int tc,i,x,y;
	scanf("%d",&tc);
	while(tc--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<N;i=i+1)
			v[i].clear();
		scanf("%d",&n);
		for(i=1;i<n;i=i+1){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		scanf("%d",&x);
		while(x--){
			scanf("%d",&y);
			a[y]=1;
		}
		scanf("%d",&x);
		while(x--){
			scanf("%d",&y);
			b[y]=1;
		}
		cout<<"B "<<y<<endl;
		scanf("%d",&x);
		y=dfs(x,0);
		cout<<"A "<<y<<endl;
		scanf("%d",&x);
		if(!b[x])
			y=-1;
		cout<<"C "<<y<<endl;
	}
	return 0;
}