#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt=1;
char s[200100],ss[200100];
struct Suffix_Automaton{int ch[26],len,fa;}t[400100];
int sz[400100];
vector<int>v[400100];
ll res;
int Add(int x,int c){
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
	t[xx].fa=t[y].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
void dfs(int x){for(auto y:v[x])dfs(y),sz[x]+=sz[y];}
int main(){
	scanf("%d%s%s",&n,s,ss);
	for(int i=0,las=1;i<n;i++)sz[las=Add(las,s[i]-'a')]+='1'-ss[i];
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
	for(int i=1;i<=cnt;i++)res=max(res,1ll*t[i].len*sz[i]);
	printf("%lld\n",res);
	return 0;
}