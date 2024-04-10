#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#define N 100100
#define Q 1000000007
using namespace std;
vector<int> g[N];
pair<int,int> DFS(int now){
	int all[2][2]={};
	int odd=1,eve=0,codd,ceve,todd,teve,csz,sw[2];
	pair<int,int> tmp;
	all[0][0]=all[1][0]=1;
	for(int i=0;i<g[now].size();i++){
		tmp=DFS(g[now][i]);
		codd=tmp.first;
		ceve=tmp.second+1;
		todd=(1LL*odd*ceve%Q+1LL*eve*codd%Q)%Q;
		teve=(1LL*eve*ceve%Q+1LL*odd*codd%Q)%Q;
		eve=teve;
		odd=todd;
		all[0][0]=1LL*all[0][0]*ceve%Q;
		sw[0]=(1LL*all[1][1]*codd%Q+all[1][0])%Q;
		sw[1]=(1LL*all[1][0]*codd%Q+all[1][1])%Q;
		all[1][1]=sw[1];
		all[1][0]=sw[0];
	}
	return make_pair(((odd+odd-all[0][0])%Q+Q)%Q,((eve+eve-all[1][1])%Q+Q)%Q);
}
int main(){
	int n,p,i;
	pair<int,int> ans;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&p);
		g[p].push_back(i);
	}
	ans=DFS(1);
	printf("%d\n",(ans.first+ans.second)%Q);
	return 0;
}