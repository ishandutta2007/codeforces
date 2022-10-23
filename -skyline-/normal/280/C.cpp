#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,d[100005];
double ans;
vector<int> v[100005];
void dfs(int x,int y){
	ans+=1.0/(d[x]=d[y]+1);
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y),v[y].pb(x);
	}
	dfs(1,0);
	printf("%.10lf\n",ans);
    return 0;
}