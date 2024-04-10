#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 1505;

int n,m;
int a[N][N],b[N][N];
int p[N];
int cmpj;
vector<int> G[N<<1];
bool cmp(int x,int y){
	return a[x][cmpj]<a[y][cmpj];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		scanf("%d",&b[i][j]);
	}
	static bool use[N<<1],vis[N];
	static int to[N];
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j)
		if(b[i][j]>b[i+1][j]){
			G[i+m].push_back(j);
			to[j]++;
		}
		else if(b[i][j]<b[i+1][j]){
			G[j].push_back(i+m);
		}
	}
	queue<int> q;
	for(int j=1;j<=m;++j)if(!to[j])q.push(j);
	vector<int> ans;
	while(!q.empty()){
		int j=q.front();q.pop();
		ans.push_back(j);
		for(int i=0;i<G[j].size();++i){
			int p=G[j][i];
			if(!use[p]){
				use[p]=1;
				for(int t=0;t<G[p].size();++t){
					int y=G[p][t];
					--to[y];
					if(!to[y]){
						q.push(y);
					}
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());
	static int id[N];
	for(int i=1;i<=n;++i)id[i]=i;
	for(int i=0;i<ans.size();++i){
		cmpj=ans[i];
		stable_sort(id+1,id+n+1,cmp);
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(a[id[i]][j]!=b[i][j]){
		puts("-1");
		return 0;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	printf("\n");
}