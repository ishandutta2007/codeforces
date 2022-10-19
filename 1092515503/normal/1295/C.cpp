#include<bits/stdc++.h>
using namespace std;
int T,n,nx[200100][26],m,res;
char s[200100],t[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),scanf("%s",t+1),n=strlen(s+1),m=strlen(t+1),res=1;
		for(int i=n+1;i<=2*n;i++)s[i]=s[i-n];
		for(int i=0;i<=2*n;i++)for(int j=0;j<26;j++)nx[i][j]=-1;
		for(int i=2*n-1;i>=0;i--){
			for(int j=0;j<26;j++)nx[i][j]=nx[i+1][j];
			nx[i][s[i+1]-'a']=i+1;
		}
//		for(int i=0;i<2*n;i++){for(int j=0;j<26;j++)printf("%d ",nx[i][j]);puts("");}
		int pos=0;
		for(int i=1;i<=m;i++){
			if(nx[pos][t[i]-'a']==-1){res=-1;break;}
			pos=nx[pos][t[i]-'a'];
			if(pos>n)pos-=n,res++;
		}
		printf("%d\n",res);
	}
	return 0;
}