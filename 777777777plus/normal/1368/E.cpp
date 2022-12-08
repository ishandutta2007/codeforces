#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,m,c[N]; 
vector<int> ans,g[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ans.clear();
		for(int i=1;i<=n;++i){
			g[i].clear();
			c[i]=0;
		}
		for(int i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			g[y].push_back(x);
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<g[i].size();++j){
				int y=g[i][j];
				if(c[y]<2){
					c[i]=max(c[i],c[y]+1);
				}
			}
			if(c[i]==2)ans.push_back(i);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		printf("\n");
	}
}