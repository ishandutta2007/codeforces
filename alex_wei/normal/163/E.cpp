#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int n,k,buc[N];
int node,ed[N],son[N][26],fa[N];
vector <int> e[N];
void ins(string s,int id){
	int p=0;
	for(char it:s){
		if(!son[p][it-'a'])son[p][it-'a']=++node;
		p=son[p][it-'a'];
	} ed[id]=p;
}
void build(){
	queue <int> q;
	for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(son[t][i])fa[son[t][i]]=son[fa[t]][i],q.push(son[t][i]);
			else son[t][i]=son[fa[t]][i];
		e[fa[t]].push_back(t);
	}
}

int dnum,dfn[N],sz[N],c[N];
void add(int x,int v){while(x<=node)c[x]+=v,x+=x&-x;}
int query(int x){int s=0; while(x)s+=c[x],x-=x&-x; return s;}
void dfs(int id){
	dfn[id]=dnum++,sz[id]=1;
	for(int it:e[id])dfs(it),sz[id]+=sz[it]; 
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		string s; cin>>s,ins(s,i);
	}
	build(),dfs(0);
	for(int i=1;i<=k;i++){
		int id=ed[i];
		add(dfn[id],1);
		add(dfn[id]+sz[id],-1);
		buc[i]=1;
	}
	for(int i=1;i<=n;i++){
		char c; cin>>c;
		if(c=='?'){
			string s; cin>>s;
			long long p=0,ans=0;
			for(char it:s){
				p=son[p][it-'a'];
				ans+=query(dfn[p]);
			}
			cout<<ans<<endl;
		}
		else if(c=='-'){
			int id; cin>>id;
			if(!buc[id])continue;
			buc[id]=0;
			id=ed[id];
			add(dfn[id],-1);
			add(dfn[id]+sz[id],1);
		}
		else if(c=='+'){
			int id; cin>>id;
			if(buc[id])continue;
			buc[id]=1;
			id=ed[id];
			add(dfn[id],1);
			add(dfn[id]+sz[id],-1);
		}
	}
	return 0;
}