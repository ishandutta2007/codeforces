#include<bits/stdc++.h>
using namespace std;
int n,m,delta,q[1001000];
struct trie{
	int ch[26],f;
	bool fin;
}t[1001000];
stack<pair<int,int> >s;
void dfs(int x){
	if(s.empty()||t[x].f-delta<s.top().second)s.push(make_pair(x,t[x].f-delta));
	delta+=t[x].fin;
	for(int i=0;i<26;i++){
		if(!t[x].ch[i])continue;
		t[t[x].ch[i]].f=t[x].f+1;
		if(!s.empty()&&t[t[x].ch[i]].fin)t[t[x].ch[i]].f=min(t[t[x].ch[i]].f,s.top().second+delta+1);
		dfs(t[x].ch[i]);
	}
	if(!s.empty()&&s.top().first==x)s.pop();
}
char str[2];
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d%s",&x,str),t[x].ch[str[0]-'a']=i;
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&q[i]),t[q[i]].fin=true;
	dfs(0);
	for(int i=1;i<=m;i++)printf("%d ",t[q[i]].f);
	return 0;
}