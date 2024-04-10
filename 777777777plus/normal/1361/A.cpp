#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n,m;
int a[N],b[N];
vector<int> g[N];

bool cmp(int x,int y){
	return a[x]<a[y];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;++i){
		int x=b[i];
		static int vis[N];
		for(int j=0;j<g[x].size();++j){
			int y=g[x][j];
			vis[a[y]]=x;
		}
		int w=1;
		while(vis[w]==x)w++;
		if(a[x]!=w){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",b[i]);
	printf("\n");
}