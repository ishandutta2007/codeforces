#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
char s[N];
int w[N],p[N],lp[N],rp[N],fa[N],c[N][26],id,t[N];
basic_string<int>g[N];
void dfs(int x){
	lp[x]=++id;
	for(int i:g[x])w[i]+=w[x],dfs(i);
	rp[x]=id;
}
void add(int x){for(;x<=id;x+=x&-x)++t[x];}
void del(int x){for(;x<=id;x+=x&-x)--t[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
bool b[N];
queue<int>q;
int main(){
	int m,n,i,j,k,l,x,id=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i){
		scanf("%s",s+1),x=0,l=strlen(s+1);
		for(j=1;j<=l;++j){
			if(k=s[j]-'a',!c[x][k])c[x][k]=++id;
			x=c[x][k];
		}
		p[i]=x,w[x]=1;
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=fa[i];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),fa[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	for(i=1;i<=id;++i)g[fa[i]]+=i;
	dfs(0);char ch;
	while(m--){
		scanf(" %c",&ch);
		if(ch=='?'){
			scanf("%s",s+1),x=0,l=strlen(s+1),k=0;
			for(j=1;j<=l;++j)x=c[x][s[j]-'a'],k+=w[x]+sum(lp[x]);
			printf("%d\n",k);
		}else if(ch=='-'){
			scanf("%d",&i),i=p[i];
			if(!b[i])b[i]=1,del(lp[i]),add(rp[i]+1);
		}else{
			scanf("%d",&i),i=p[i];
			if(b[i])b[i]=0,add(lp[i]),del(rp[i]+1);
		}
	}
	return 0;
}