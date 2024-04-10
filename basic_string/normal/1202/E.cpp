#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
char t[N],s[N];
int p[N];
struct AC{
int c[N][26],f[N],w[N],q[N],id;
void ins(char*s){
	int x=0,j;
	for(;*s;++s){
		j=*s-'a';
		if(!c[x][j])c[x][j]=++id;
		x=c[x][j];
	}
	++w[x];
}
void bd(){
	int i,k,l,j,x;
	for(i=k=l=0;i<26;++i)if(c[0][i])q[++l]=c[0][i];
	while(k<l){
		i=q[++k],x=f[i];
		for(j=0;j<26;++j)if(c[i][j])q[++l]=c[i][j],f[c[i][j]]=c[x][j];
		else c[i][j]=c[x][j];
	}
	for(i=1;i<=l;++i)w[q[i]]+=w[f[q[i]]];
}
}A,B;
int main(){
	int n,i,j,k,l,x,id=0;
	long long ans=0;
	scanf("%s%d",t+1,&n);
	while(n--){
		scanf("%s",s+1),l=strlen(s+1),A.ins(s+1);
		reverse(s+1,s+l+1),B.ins(s+1);
	}
	A.bd(),B.bd();
	for(l=strlen(t+1),i=1,x=0;i<=l;++i)x=A.c[x][t[i]-'a'],p[i]=A.w[x];
	for(i=l,x=0;i;--i)x=B.c[x][t[i]-'a'],ans+=B.w[x]*1ll*p[i-1];
	printf("%lld",ans);
	return 0;
}