#include<bits/stdc++.h>
using namespace std;
int T,n,sum[3];
char s[310][310];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<3;i++)sum[i]=0;
		for(int i=0;i<n;i++)scanf("%s",s[i]);
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(s[i][j]!='.')sum[(i+j+(s[i][j]=='O'))%3]++;
		int mn=0;
		for(int i=1;i<3;i++)if(sum[i]<sum[mn])mn=i;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(s[i][j]!='.'){
			if((i+j)%3==mn)s[i][j]='O';
			if((i+j+1)%3==mn)s[i][j]='X';
		}
		for(int i=0;i<n;i++)printf("%s\n",s[i]);
	}
	return 0;
}