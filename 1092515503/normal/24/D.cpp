#include<bits/stdc++.h> 
using namespace std;
int n,m,X,Y;
double f[1010][1010];
int main(){
	scanf("%d%d%d%d",&m,&n,&X,&Y),m-=X-1,X=1;
	if(m==1){puts("0");return 0;}
	if(n==1){printf("%d\n",(m-1)*2);return 0;}
	for(int i=1;i<m;i++)for(int tmp=1;tmp<=50;tmp++)for(int j=1;j<=n;j++){
		if(j==1)f[i][j]=(f[i][j+1]+f[i][j]+f[i-1][j])/3+1;
		else if(j==n)f[i][j]=(f[i][j-1]+f[i][j]+f[i-1][j])/3+1;
		else f[i][j]=(f[i-1][j]+f[i][j]+f[i][j-1]+f[i][j+1])/4+1;
	}
	printf("%lf\n",f[m-1][Y]);
	return 0;
}