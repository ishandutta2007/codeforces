//CF 986A
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
const int N = 111111;
const int K = 111;
int n,m,k,s,a[N],d[N][K];
vector<int> v[N];
queue<int> q;
void bfs(int w){
	int i,x;
	for(i=1;i<=n;i=i+1){
		d[i][w]=N;
		if(a[i]==w)
			d[i][w]=0,q.push(i);
	}
	while(!q.empty()){
		i=q.front();
		q.pop();
		for(x=v[i].size();x--;){
			if(d[v[i][x]][w]==N)
				d[v[i][x]][w]=d[i][w]+1,q.push(v[i][x]);
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=k;i=i+1)
		bfs(i);
	for(i=1;i<=n;i=i+1){
		sort(d[i]+1,d[i]+k+1);
		y=0;
		for(x=1;x<=s;x=x+1)
			y+=d[i][x];
		printf("%d ",y);
	}
	return 0;
}