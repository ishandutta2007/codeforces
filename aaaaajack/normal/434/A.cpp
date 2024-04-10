#include<cstdio>
#include<algorithm>
#include<vector>
#define iabs(n) ((n)>0?(n):-(n))
#define N 100100
using namespace std;
vector<int> g[N];
int p[N];
long long tt[N]={0};
int main(){
	int i,j,n,m;
	long long ans,ori=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&p[i]);
		if(i){
			if(p[i]!=p[i-1]){
				g[p[i-1]].push_back(p[i]);
				g[p[i]].push_back(p[i-1]);
				tt[p[i-1]]+=iabs(p[i]-p[i-1]);
				tt[p[i]]+=iabs(p[i]-p[i-1]);
				ori+=iabs(p[i]-p[i-1]);
			}
		}
	}
	ans=ori;
	for(i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
		for(j=0;j<g[i].size()/2;j++){
			tt[i]-=g[i][g[i].size()-1-j]-g[i][j];
		}
		if(ori-tt[i]<ans) ans=ori-tt[i];
	}
	printf("%I64d\n",ans);
	return 0;
}