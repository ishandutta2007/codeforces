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
int n,m,X[200100],Y[200100],dep[200100],fa[200100];
vector<int>v[200100];
char s[200100];
int fi[200100];
bool vis[200100];
void dfs(int x){
	// printf("%d\n",x);
	vis[x]=true;
	for(auto i:v[x]){
		int y=X[i]^Y[i]^x;
		if(vis[y])continue;
		// printf("%d->%d:%d\n",x,y,i);
		s[i]='1',fi[y]=i,dep[y]=dep[x]+1,fa[y]=x;
		dfs(y);
	}
}
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)v[i].clear(),vis[i]=false;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&X[i],&Y[i]),v[X[i]].push_back(i),v[Y[i]].push_back(i),s[i]='0';
	s[m+1]=0;
	dfs(1);
	if(m<n+2){printf("%s\n",s+1);return;}
	vector<int>u;
	for(int i=1;i<=m;i++)if(s[i]=='0')u.push_back(i);
	vector<int>w;
	for(auto i:u)w.push_back(X[i]),w.push_back(Y[i]);
	sort(w.begin(),w.end()),w.resize(unique(w.begin(),w.end())-w.begin());
	if(w.size()>3){printf("%s\n",s+1);return;}
	// for(int i=2;i<=n;i++)printf("|%d:%d,%d|\n",fi[i],X[fi[i]],Y[fi[i]]);
	int i=u[0];
	int x=X[i],y=Y[i];
	if(dep[x]>dep[y])swap(x,y);
	// printf("<%d,%d>\n",x,y);
	while(dep[y]>dep[x]+1)y=fa[y];
	s[i]='1',s[fi[y]]='0';
	printf("%s\n",s+1);
	// puts("$$$");
	// for(int i=1;i<=m;i++)if(s[i]=='0')printf("%d %d\n",X[i],Y[i]);
	// puts("!!!");
	// for(int i=1;i<=m;i++)if(s[i]=='1')printf("%d %d\n",X[i],Y[i]);
	// puts("###");
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}