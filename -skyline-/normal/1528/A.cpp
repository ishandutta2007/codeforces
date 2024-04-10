#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,l[100005],r[100005];
ll f[100005][2];
vector<int> v[100005];
void dfs(int x,int y){
	f[x][0]=f[x][1]=0;
	for(int i=0;i<v[x].size();++i){
		int z=v[x][i];
		if(y==z) continue;
		dfs(z,x);
		f[x][0]+=max(abs(l[x]-l[z])+f[z][0],abs(l[x]-r[z])+f[z][1]);
		f[x][1]+=max(abs(r[x]-l[z])+f[z][0],abs(r[x]-r[z])+f[z][1]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",l+i,r+i),v[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].pb(y),v[y].pb(x);
		}
		dfs(1,0);
		printf("%I64d\n",max(f[1][0],f[1][1]));
	}
    return 0;
}