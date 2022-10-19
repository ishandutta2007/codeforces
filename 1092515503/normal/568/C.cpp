#include<bits/stdc++.h>
using namespace std;
char s[30],t[210],r[210];
int n,m,V,dfn[410],low[410],tot,stk[410],tp,col[410],c;
vector<int>v[410],u[410],w[2];
void Tarjan(int x){
	dfn[x]=low[x]=++tot,stk[++tp]=x;
	for(auto y:v[x]){
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(!col[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]!=low[x])return;
	c++;int y;do col[y=stk[tp--]]=c;while(y!=x);
}
int cho[410];
void attempt(int x,int pos){if(cho[x]&&cho[x]<pos)return;cho[x]=pos;for(auto y:u[x])attempt(y,pos);}
bool dfs(int pos,bool lim){
//	printf("%d %d\n",pos,lim);
	if(pos>n)return true;
	if(lim){
		bool sd=(s[t[pos]-'a']=='C');
		attempt(col[pos+(sd?n:0)],pos);
		bool ok=true;
		for(int i=1;i<=n;i++)if(cho[col[i]]&&cho[col[i+n]])ok=false;
		if(ok){
			r[pos]=t[pos];
			if(dfs(pos+1,lim))return true;
		}
		for(int i=1;i<=c;i++)if(cho[i]==pos)cho[i]=0;
	}
	bool occ[2]={false,false};
	for(int i=(lim?t[pos]-'a'+1:0);i<V;i++){
		if(occ[s[i]=='C'])continue;occ[s[i]=='C']=true;
		attempt(col[pos+(s[i]=='C'?n:0)],pos);
		bool ok=true;
		for(int j=1;j<=n;j++)if(cho[col[j]]&&cho[col[j+n]])ok=false;
		if(ok){
			r[pos]='a'+i;
			if(dfs(pos+1,false))return true;	
		}
		for(int j=1;j<=c;j++)if(cho[j]==pos)cho[j]=0;
	}
	return false;
}
int main(){
	scanf("%s",s),V=strlen(s);
	for(int i=0;i<V;i++)w[s[i]=='C'].push_back(i);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%s%d%s",&x,t,&y,t+2);
		v[x+(t[0]=='C'?n:0)].push_back(y+(t[2]=='C'?n:0));
		v[y+(t[2]=='C'?0:n)].push_back(x+(t[0]=='C'?0:n));
	}
	for(int i=1;i<=(n<<1);i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)if(col[i]==col[i+n]){puts("-1");return 0;}
//	for(int i=1;i<=n;i++)printf("%d ",col[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",col[i+n]);puts("");
	for(int i=1;i<=(n<<1);i++)for(auto j:v[i])if(col[i]!=col[j])u[col[i]].push_back(col[j]);
	for(int i=1;i<=c;i++)sort(u[i].begin(),u[i].end()),u[i].resize(unique(u[i].begin(),u[i].end())-u[i].begin());
//	for(int i=1;i<=c;i++,puts(""))for(auto j:u[i])printf("%d ",j);
	scanf("%s",t+1);
	if(!dfs(1,true))puts("-1");
	else printf("%s\n",r+1);
	return 0;
}