#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m,a,b,f[6][6]; 
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		f[a][b]=f[b][a]=1;
	}
	for(int i=1;i<=3;i++)for(int j=i+1;j<=4;j++)for(int k=j+1;k<=5;k++){
		int s=f[i][j]+f[j][k]+f[i][k];
		if(s==0||s==3)puts("WIN"),exit(0);
	}
	puts("FAIL");
    return 0;
}