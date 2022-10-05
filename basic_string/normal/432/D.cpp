#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int p[N],f[N],u[N];
int main(){
	int n,i,j;
	scanf("%s",s+1),n=strlen(s+1);
	for(i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=p[j];
		if(s[i]==s[j+1])p[i]=++j;
	}
	for(i=n;i;--i)f[p[i]]+=(++f[i]);
	for(i=n,j=0;i;i=p[i])u[++j]=i;
	for(printf("%d\n",j);j;--j)printf("%d %d\n",u[j],f[u[j]]);
	return 0;
}