#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char s[30][30];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if(s[i-1][j-1]=='1'||s[i-1][j]=='1'||s[i][j-1]=='1'||s[i-1][j+1]=='1'||i>1&&i<n&&j>1&&j<m)s[i][j]='0';
			else s[i][j]='1';
		}
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)putchar(s[i][j]);putchar('\n');}putchar('\n');
	}
	return 0;
}