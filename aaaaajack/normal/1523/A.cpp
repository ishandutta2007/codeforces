#include<bits/stdc++.h>
#define N 1100
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,j=0;
		scanf("%d%d",&n,&m);
		char s[2][N]={};
		scanf("%s",s[0]);
		for(int i=0;i<min(n,m);i++){
			for(int j=0;j<n;j++){
				if(s[i&1][j]=='1') s[(i+1)&1][j]='1';
				else if((j && s[i&1][j-1]=='1')!=(j+1<n && s[i&1][j+1]=='1')) s[(i+1)&1][j]='1';
				else s[(i+1)&1][j]='0';
			}
		}
		puts(s[min(n,m)&1]);
	}
	return 0;
}