/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,p[100100],K;
vector<int>v[100100];
bool ed[100100];
void dfs(int x){for(auto y:v[x])printf("%d ",y),dfs(y);}
void mina(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)ed[i]=false,v[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(K=1;K<=n;K++)if(p[K]<K)break;K--;
	for(int i=1;i<=n;i++){
		if(p[i]==0||p[i]==n+1)p[i]=0;
		ed[p[i]]=true,v[p[i]].push_back(i);
	}
	for(int i=0;i<=n;i++)sort(v[i].begin(),v[i].end(),[](const int&u,const int&v){return ed[u]<ed[v];});
	printf("%d\n",K);
	dfs(0);puts("");
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}