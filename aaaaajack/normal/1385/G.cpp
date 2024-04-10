#include<bits/stdc++.h>
#define N 200100
using namespace std;
vector<int> g[N],d[N];
bool vis[N];
int a[2][N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				g[a[i][j]].push_back(a[i^1][j]);
				d[a[i][j]].push_back(j<<1|i);
			}
		}
		bool fail=false;
		for(int i=1;i<=n;i++){
			if(g[i].size()!=2) fail=true;
		}
		if(fail) puts("-1");
		else{
			vector<int> ans;
			for(int u=1;u<=n;u++){
				vector<int> v[2];
				int p=-1;
				while(!vis[u]){
					vis[u]=true;
					if(d[u][0]==(p^1)){
						p=d[u][1];
						u=g[u][1];
					}
					else{
						p=d[u][0];
						u=g[u][0];
					}
					v[p&1].push_back(p>>1);
				}
				//luckily self loop isn't a problem
				if(v[0].size()<v[1].size()) ans.insert(ans.end(),v[0].begin(),v[0].end());
				else ans.insert(ans.end(),v[1].begin(),v[1].end());
			}
			printf("%d\n",(int)ans.size());
			sort(ans.begin(),ans.end());
			for(auto x:ans) printf("%d ",x+1);
			puts("");
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			d[i].clear();
			vis[i]=false;
		}
	}
}