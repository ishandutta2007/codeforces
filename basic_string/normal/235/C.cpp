#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char s[N];
int fa[N],len[N],t[N][26],d[N],c[N],p[N],mk[N],x=1,id=1;
void ins(int c){
	int y=x;
	len[x=++id]=len[y]+1,d[x]=1;
	for(;y&&!t[y][c];y=fa[y])t[y][c]=x;
	if(!y){fa[x]=1;return;}
	int z=t[y][c];
	if(len[z]==len[y]+1){fa[x]=z;return;}
	len[++id]=len[y]+1,fa[id]=fa[z],memcpy(t[id],t[z],104),fa[z]=fa[x]=id;
	for(;y&&t[y][c]==z;y=fa[y])t[y][c]=id;
}
int main(){
	int n,i,j,k,l,g,q,ans;
	scanf("%s%d",s,&q),n=strlen(s),len[0]=-1;
	for(i=0;i<n;++i)ins(s[i]-'a');
	for(i=1;i<=id;++i)++c[len[i]];
	for(i=1;i<=n;++i)c[i]+=c[i-1];
	for(i=1;i<=id;++i)p[c[len[i]]--]=i;
	for(i=id;i;--i)d[fa[p[i]]]+=d[p[i]];
	for(g=1;g<=q;++g){
		scanf("%s",s),n=strlen(s),ans=0;
		for(i=l=0,j=1;i<n;++i){
			for(k=s[i]-'a';j&&!t[j][k];j=fa[j],l=len[j]);
			if(!j)j=1,l=0;
			else j=t[j][k],++l;
		}
		for(i=0;i<n;++i){
			if(l==n){
				if(mk[j]!=g)mk[j]=g,ans+=d[j];
				--l;
				if(l==len[fa[j]])j=fa[j];
			}
			for(k=s[i]-'a';j&&!t[j][k];j=fa[j],l=len[j]);
			if(!j)j=1,l=0;
			else j=t[j][k],++l;
		}
		printf("%d\n",ans);
	}
	return 0;
}