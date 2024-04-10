#include<bits/stdc++.h>
using namespace std;
const int N=109,P=1e9+9;
char s[N];
int to[N],c[N][26],fa[N],d[N],len[N];
long long f[N][13],g[N][13];
queue<int>q;
int main(){
	to['C']=1,to['G']=2,to['T']=3;
	int n,m,i,j,l,x,id=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%s",s+1),l=strlen(s+1),x=0;
		for(i=1;i<=l;x=c[x][j],++i)if(j=to[s[i]],!c[x][j])c[x][j]=++id,d[id]=i;
		len[x]=l;
	}
	for(i=0;i<4;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),x=fa[i],len[i]=max(len[i],len[fa[i]]);
		for(j=0;j<4;++j)if(c[i][j])q.push(c[i][j]),fa[c[i][j]]=c[x][j];
		else c[i][j]=c[x][j];
	}
	for(f[0][0]=1;n--;){
		memcpy(g,f,sizeof g),memset(f,0,sizeof f);
		for(i=0;i<=id;++i)for(j=0;j<4;++j)for(l=d[x=c[i][j]]-1;~l;--l)
		f[x][(l+1<=len[x])?0:l+1]+=g[i][l];
		for(i=0;i<=id;++i)for(l=d[i];~l;--l)f[i][l]%=P;
	}
	for(i=0,j=0;i<=id;++i)j=(j+f[i][0])%P;
	printf("%d",(j+P)%P);
	return 0;
}