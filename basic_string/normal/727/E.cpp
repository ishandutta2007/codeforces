#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
char s[N],t[N];
int c[N][26],f[N],ed[N],p[N],st[N];
bool b[N];
queue<int>q;
int main(){
	int n,m,g,i,j,k,id=0,tp,x;
	scanf("%d%d%s",&n,&m,s+1),n*=m;
	for(i=1;i<m;++i)s[++n]=s[i];
	for(scanf("%d",&g),k=1;k<=g;++k){
		scanf("%s",t+1);
		for(i=1,x=0;i<=m;x=c[x][j],++i)if(j=t[i]-'a',!c[x][j])c[x][j]=++id;
		ed[x]=k;
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=f[i];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	for(i=1,x=0;i<=n;++i)x=c[x][s[i]-'a'],p[i]=ed[x];
	for(i=m;i<m*2;++i){
		for(tp=0,j=i;j<=n;b[p[j]]=1,st[++tp]=p[j],j+=m)if(!p[j]||b[p[j]])goto gg;
		for(j=1,puts("YES");j<=tp;++j)printf("%d ",st[j]);
		return 0;
		gg:;
		for(;tp;--tp)b[st[tp]]=0;
	}
	puts("NO");
	return 0;
}