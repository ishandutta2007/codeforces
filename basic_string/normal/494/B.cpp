#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9,P=1e9+7;
char s[N],t[N];
int p[N],f[N],g[N];
int main(){
	int n,m,i,j,u=0;
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(j=0,i=2;i<=m;++i){
		while(j&&t[i]!=t[j+1])j=p[j];
		if(t[i]==t[j+1])++j;
		p[i]=j;
	}
	for(j=0,i=1;i<=n;++i){
		if(i>m)u=(u+g[i-m])%P;
		while(j&&s[i]!=t[j+1])j=p[j];
		if(s[i]==t[j+1])++j;
		if(j==m)f[i]=(u+i-m+1)%P,j=p[j];
		else f[i]=f[i-1];
		g[i]=(g[i-1]+f[i])%P;
	}
	printf("%d",g[n]);
	return 0;
}