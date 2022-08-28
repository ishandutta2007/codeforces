//CF 920E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
const int W = 1000;
int n,m,a[N],b[N],vis[N];
vector<int> v[N],ans;
int dfs(int u){
	int i,j=0,z=v[u].size(),s=1;
	vis[u]=1;
	for(i=1;i<=n;i=i+1){
		if(j<z&&v[u][j]==i){
			j++;
			continue;
		}
		if(u==i)
			continue;
		if(!b[i])
			return 0;
		if(!vis[i])
			s+=dfs(i);
	}
	return s;
}
int main()
{
	int i,x,y,s;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		a[x]++,a[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1){
		sort(v[i].begin(),v[i].end());
		if(n-a[i]<W)
			b[i]=1;
	}
	s=n;
	for(i=1;i<=n;i=i+1)
		if(b[i]&&!vis[i]){
			x=dfs(i);
			if(x){
				ans.push_back(x);
				s-=x;
			}
		}
	if(s)
		ans.push_back(s);
	sort(ans.begin(),ans.end());
	s=ans.size();
	printf("%d\n",s);
	for(i=0;i<s;i=i+1)
		printf("%d ",ans[i]);
	return 0;
}