#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
char s[N];
int u,v,w,c[N][26],f[N],ed[N],st[N*80],s2[N*80],tp,la[N],t,mx[N*4],ans[N],a[N];
queue<int>q;
basic_string<int>g[N],o[N];
struct U{int l,r,x;};
vector<U>vc[N];
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		if(mx[k]<w)st[++tp]=k,s2[tp]=mx[k],mx[k]=w;
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void qry(int k,int l,int r){
	if(ans[u]=max(ans[u],mx[k]),l==r)return;
	int m=l+r>>1;
	u>m?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
void dfs(int x){
	int z=tp;
	for(auto o:vc[x])if(u=o.l,v=o.r,u<=v)w=o.x,upd(1,1,t);
	for(int i:o[x])u=i,qry(1,1,t);
	for(int i:g[x])dfs(i);
	for(;tp>z;--tp)mx[st[tp]]=s2[tp];
}
int main(){
	int n,m,i,j,k,l,x,id=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%s",s+1),l=strlen(s+1);
		for(j=1,x=0;j<=l;++j){
			if(k=s[j]-'a',!c[x][k])c[x][k]=++id;
			x=c[x][k];
		}
		ed[i]=x;
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=f[i];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	for(i=1;i<=id;++i)g[f[i]]+=i;
	while(m--)if(scanf("%d",&i),i==1){
		scanf("%d%d",&i,&k),j=ed[i];
		vc[j].push_back({la[i]+1,t,a[i]}),la[i]=t,a[i]=k;
	}else{
		scanf("%s",s+1),l=strlen(s+1),++t;
		for(j=1,x=0;j<=l;++j)if(x=c[x][s[j]-'a'],x)o[x]+=t;
	}
	for(i=1;i<=n;++i)j=ed[i],vc[j].push_back({la[i]+1,t,a[i]});
	memset(ans,-1,sizeof ans),memset(mx,-1,sizeof mx),dfs(0);
	for(i=1;i<=t;++i)printf("%d\n",ans[i]);
	return 0;
}