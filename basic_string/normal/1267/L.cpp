#include<bits/stdc++.h>
using namespace std;
char s[1000009],c[1009][1009];
int f[139];
int main(){
	int n,l,k,p,q,i,j,L,r,u,v;
	scanf("%d%d%d%s",&n,&l,&k,s+1),p=n*l;
	for(i=1;i<=p;++i)++f[s[i]];
	for(i=1,j=0;i<131;++i)while(f[i]--)s[++j]=i;
	L=0,r=k*l+1,u=1;
	for(i=1;i<=l;++i){
		for(j=u;j<=k;++j)c[j][i]=s[++L];
		v=u;
		while(c[v][i]!=c[k][i])++v;
		for(j=v-1;j>=u;--j){
			for(p=i+1;p<=l;++p)c[j][p]=s[--r];
		}
		u=v;
	}
	for(i=1;i<=k;++i){
		for(j=1;j<=l;++j)putchar(c[i][j]);
		putchar(10);
	}
	p=k*l;
	for(i=k+1;i<=n;++i){
		for(j=1;j<=l;++j)putchar(s[++p]);
		putchar(10);
	}
	return 0;
}