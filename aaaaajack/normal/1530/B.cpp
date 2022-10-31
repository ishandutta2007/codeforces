#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	char s[100][100];
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) s[i][j]='0';
			s[i][m]=0;
		}
		if(n&1){
			for(int i=0;i<n;i+=2){
				s[i][0]=s[i][m-1]='1';
			}
			for(int j=2;j<m-2;j+=2){
				s[0][j]=s[n-1][j]='1';
			}
		}
		else{
			for(int j=0;j<m;j+=2){
				s[0][j]=s[n-1][j]='1';
			}
			for(int i=2;i<n-2;i+=2){
				s[i][0]=s[i][m-1]='1';
			}
		}
		for(int i=0;i<n;i++) puts(s[i]);
		puts("");
	}
	return 0;
}