//CF 938D
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
int n,m;
vector<int> v[N];
vector<LL> h[N];
LL d[N];
priority_queue<pair<LL,int> > Q;
int main()
{
	int i,x,y;
	LL z;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%lld",&x,&y,&z);
		z=z+z;
		v[x].push_back(y);
		h[x].push_back(z);
		v[y].push_back(x);
		h[y].push_back(z);
	}
	for(i=1;i<=n;i=i+1){
		scanf("%lld",&z);
		v[0].push_back(i);
		h[0].push_back(z);
		d[i]=1e18;
	}
	Q.push(make_pair(0,0));
	while(!Q.empty()){
		x=Q.top().second;
		z=-Q.top().first;
		Q.pop();
		if(d[x]!=z)
			continue;
		i=v[x].size();
		while(i--){
			y=v[x][i];
			z=h[x][i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				Q.push(make_pair(-d[y],y));
			}
		}
	}
	for(i=1;i<=n;i=i+1)
		printf("%lld ",d[i]);
	return 0;
}