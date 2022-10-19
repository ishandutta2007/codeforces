#include<bits/stdc++.h>
using namespace std;
int n,tot=1,head[100100],cnt,sz[100100],kmp[100100],res;
struct Edge{
	int to,next;
}edge[100100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
struct AC_Automaton{
	int ch[26],fail;
}t[100100];
char s[100100];
void ins(){
	int x=1;
	for(int i=0;i<n;i++){
		t[x].ch[s[i]-'A']=++tot;
		x=t[x].ch[s[i]-'A'];
	}
}
queue<int>q;
void build(){
	for(int i=0;i<26;i++){
		if(t[1].ch[i])t[t[1].ch[i]].fail=1,ae(1,t[1].ch[i]),q.push(t[1].ch[i]);
		else t[1].ch[i]=1;
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(t[x].ch[i])t[t[x].ch[i]].fail=t[t[x].fail].ch[i],ae(t[t[x].fail].ch[i],t[x].ch[i]),q.push(t[x].ch[i]);
			else t[x].ch[i]=t[t[x].fail].ch[i];
		}
	}
}
void dfs(int x){
	sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)dfs(edge[i].to),sz[x]+=sz[edge[i].to];
}
void KMP(){
	int j=-1;
	kmp[0]=-1;
	for(int i=1;i<n;i++){
		while(j!=-1&&s[j+1]!=s[i])j=kmp[j];
		if(s[j+1]==s[i])j++;
		kmp[i]=j;
	}
}
stack<pair<int,int> >stk;
int main(){
	scanf("%s",s),n=strlen(s),memset(head,-1,sizeof(head));
	ins(),build(),dfs(1),KMP();
	for(int i=0;i<n;i++)sz[i]=sz[i+2];
	for(int i=n-1;i!=-1;i=kmp[i])stk.push(make_pair(i+1,sz[i]));
	printf("%d\n",stk.size());
	while(!stk.empty())printf("%d %d\n",stk.top().first,stk.top().second),stk.pop();
	return 0;
}