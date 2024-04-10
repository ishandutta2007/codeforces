#include<bits/stdc++.h>
using namespace std;
char s[509][509];
int main(){
	int T,n,m,o,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),o=n;
		if(n%3==1)++o;
		for(i=n==o?1:2;i<=o;++i)scanf("%s",s[i]+1);
		for(i=2;i<=o;i+=3)memset(s[i]+1,'X',m);
		for(i=4;i<=o;i+=3){
			for(j=1;j<=m;++j)if(s[i-1][j]=='X'||s[i][j]=='X'){s[i-1][j]=s[i][j]='X';goto gg;}
			s[i-1][1]=s[i][1]='X';
			gg:;
		}
		for(i=n==o?1:2;i<=o;++i)printf("%s\n",s[i]+1);
	}
	return 0;
}