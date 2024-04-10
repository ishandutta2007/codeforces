#include<bits/stdc++.h>
using namespace std;
int n,mod,f[3][410][410][2],C[410][410],res;//1:las greater than now
int main(){
	scanf("%d%d",&n,&mod);
	f[1][1][1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)for(int k=1;k<=j;k++)for(int S=0;S<2;S++){
			(f[i%3][j][k][S]+=f[i%3][j][k-1][S])%=mod;
			if(i+2<=n)(f[(i+2)%3][j+1][1][1]+=f[i%3][j][k][S])%=mod;
			if(i+1<=n){
				if(S){
					(f[(i+1)%3][j+1][1][1]+=f[i%3][j][k][S])%=mod;
					(f[(i+1)%3][j+1][k+1][1]+=mod-f[i%3][j][k][S])%=mod;
				}	
				(f[(i+1)%3][j+1][k+1][0]+=f[i%3][j][k][S])%=mod;
			}
			if(i==n)(res+=f[i%3][j][k][S])%=mod;
		}	
		memset(f[i%3],0,sizeof(f[i%3]));
	}
	printf("%d\n",res);
	return 0;
}