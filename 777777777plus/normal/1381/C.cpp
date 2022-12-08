#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,x,y;
int a[N],ans[N];
vector<int> g[N];
pair<int,int> f[N];
priority_queue<pair<int,int>> q;

void Solve(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n+1;++i)g[i].clear();
	for(int i=1;i<=n;++i)ans[i]=0;
	y-=x;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
	}
	int rest=-1;
	for(int i=1;i<=n+1;++i)
	if(!g[i].size()){
		rest=i;
	}
	else{
		q.push({g[i].size(),i});
	}
	assert(rest!=-1);
	for(int i=1;i<=x;++i){
		pair<int,int> p=q.top();q.pop();
		ans[g[p.second][p.first-1]]=p.second;
		--p.first;
		if(p.first>0){
			q.push(p);
		}
	}
	f[1]={0,0};
	int m=0;
	while(!q.empty()){
		f[++m]=q.top();q.pop();
	}
	if(f[1].first>(n-x)/2){
		if(y>(n-x-f[1].first)*2){
			puts("NO");
			return;
		}
		else{
			for(int i=2,cnt=0;i<=m;++i){
				for(int j=0;j<f[i].first;++j){
					if(y>0){
						ans[g[f[1].second][cnt]]=f[i].second;
						--y;
					}
					++cnt;
					if(y>0){
						ans[g[f[i].second][j]]=f[1].second;
						--y;
					}
				}
			}
		}
	}
	else{
		static pair<int,int> q[N];
		int cnt=0;
		for(int i=1;i<=m;++i){
			for(int j=0;j<f[i].first;++j){
				q[cnt++]={g[f[i].second][j],f[i].second};
			}
		}
		int step=f[1].first;
		for(int i=0;i<cnt;++i){
			if(y>0){
				ans[q[i].first]=q[(i+step)%cnt].second;
				--y;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		if(!ans[i])printf("%d ",rest);
		else printf("%d ",ans[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d",&T);
	while(T--){
		Solve();
	}
}