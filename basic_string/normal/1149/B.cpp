#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int f[253][253][253],t[N][29],p[29],l[4];
char o[N],s[4][253];
int main(){
	int n,q,i,j,k;
	char c;
	scanf("%d%d%s",&n,&q,o+1),fill(p,p+29,n+1),fill(t[n+1],t[n+1]+29,n+1);
	for(i=n;~i;--i){
		for(j=0;j<26;++j)t[i][j]=p[j];
		p[o[i]-'a']=i;
	}
	while(q--){
		scanf(" %c%d",&c,&i);
		if(c=='-')--l[i];
		else{
			scanf(" %c",&c),s[i][++l[i]]=c;
			if(i==1){
				for(j=0;j<=l[2];++j)for(k=0;k<=l[3];++k){
					int&u=f[l[1]][j][k];
					u=t[f[l[1]-1][j][k]][s[1][l[1]]-'a'];
					if(j)u=min(u,t[f[l[1]][j-1][k]][s[2][j]-'a']);
					if(k)u=min(u,t[f[l[1]][j][k-1]][s[3][k]-'a']);
				}
			}else if(i==2){
				for(j=0;j<=l[1];++j)for(k=0;k<=l[3];++k){
					int&u=f[j][l[2]][k];
					u=t[f[j][l[2]-1][k]][s[2][l[2]]-'a'];
					if(j)u=min(u,t[f[j-1][l[2]][k]][s[1][j]-'a']);
					if(k)u=min(u,t[f[j][l[2]][k-1]][s[3][k]-'a']);
				}
			}else{
				for(j=0;j<=l[1];++j)for(k=0;k<=l[2];++k){
					int&u=f[j][k][l[3]];
					u=t[f[j][k][l[3]-1]][s[3][l[3]]-'a'];
					if(j)u=min(u,t[f[j-1][k][l[3]]][s[1][j]-'a']);
					if(k)u=min(u,t[f[j][k-1][l[3]]][s[2][k]-'a']);
				}
			}
		}
		puts(f[l[1]][l[2]][l[3]]!=n+1?"YES":"NO");
	}
	return 0;
}