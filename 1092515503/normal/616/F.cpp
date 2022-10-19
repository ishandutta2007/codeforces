#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt=1,S;
struct Suffix_Automaton{int ch[26],len,fa;}t[1000100];
int Add(int x,int c){
	if(t[x].ch[c]){
		int y=t[x].ch[c];
		if(t[y].len==t[x].len+1)return y;//(x,c) has been added into the tree already.
		int yy=++cnt;t[yy]=t[y];
		t[yy].len=t[x].len+1,t[y].fa=yy;
		for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
		return yy;
	}
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y];
	t[yy].len=t[x].len+1;
	t[y].fa=t[xx].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
char s[500100];
vector<int>id[100100],v[1001000];
ll res,f[1001000];
void dfs(int x){for(auto y:v[x])dfs(y),f[x]+=f[y];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s),S=strlen(s);
		for(int j=0,las=1;j<S;j++)id[i].push_back(las=Add(las,s[j]-'a'));
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		for(auto j:id[i])f[j]+=x;
	}
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
	for(int i=1;i<=cnt;i++)res=max(res,f[i]*t[i].len);
	printf("%lld\n",res);
	return 0;
}