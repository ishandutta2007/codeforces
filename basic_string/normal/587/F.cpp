#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,B=333;
string s[N];
int c[N][26],f[N],n,qu[N],w[N],ed[N];
long long ps[N],ans[N];
basic_string<int>e[N],g[N],bq[N],sq[N];
struct Q{int l,r,k;}o[N];
namespace BL{
int s[N],bl[N],r[N],s2[B],m;
void in(){
	for(int i=1;i<=n;++i)r[bl[i]=i/B]=i;
	m=bl[n];
}
void add(int x,int v){
	int i;
	for(i=r[bl[x]];i>=x;--i)s[i]+=v;
	for(i=bl[x];i<=m;++i)s2[i]+=v;
}
int sum(int x){return s[x]+s2[bl[x]-1];}
}
void dfs(int x){
	for(int i:e[x])BL::add(i,1);
	for(int i:sq[x])ans[i]+=BL::sum(o[i].r)-BL::sum(o[i].l);
	for(int i:g[x])dfs(i);
	for(int i:e[x])BL::add(i,-1);
}
int main(){
	int q,i,x,j,id=0,h=0,t=0;
	for(ios::sync_with_stdio(0),cin>>n>>q,i=1;i<=n;ed[i]=x,e[x]+=i++){
		cin>>s[i],x=0;
		for(char o:s[i]){
			if(j=o-'a',!c[x][j])c[x][j]=++id;
			x=c[x][j];
		}
	}
	for(i=0;i<26;++i)if(c[0][i])qu[++t]=c[0][i];
	while(h<t){
		i=qu[++h],x=f[i],g[x]+=i;
		for(j=0;j<26;++j)if(c[i][j])f[qu[++t]=c[i][j]]=c[x][j];else c[i][j]=c[x][j];
	}
	for(i=1;i<=q;++i)if(cin>>o[i].l>>o[i].r>>o[i].k,--o[i].l,s[j=o[i].k].size()>B)bq[j]+=i;else{
		x=0;
		for(char u:s[j])x=c[x][u-'a'],sq[x]+=i;
	}
	for(i=1;i<=n;++i)if(bq[i].size()){
		x=0,memset(w,0,t*4+4);
		for(char u:s[i])x=c[x][u-'a'],++w[x];
		for(j=t;j;--j)w[f[qu[j]]]+=w[qu[j]];
		for(j=1;j<=n;++j)ps[j]=ps[j-1]+w[ed[j]];
		for(int u:bq[i])ans[u]=ps[o[u].r]-ps[o[u].l];
	}
	for(BL::in(),dfs(0),i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}