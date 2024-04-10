#include<bits/stdc++.h>
using namespace std;
int n,m,f[6][6][5][15625],a[7],b[6],c[7][6],pov[7],res=0x3f3f3f3f;
void chmn(int&x,int y){if(x>y)x=y;}
int main(){
	scanf("%d%d",&n,&m),memset(f,0x3f,sizeof(f));
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int sta=0;
	pov[0]=1;for(int i=1;i<=m;i++)pov[i]=pov[i-1]*5;
	for(int i=0;i<m;i++)scanf("%d",&b[i]),sta+=b[i]*pov[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&c[i][j]);
	f[0][0][a[0]][sta]=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<=a[i];k++)for(int l=0;l<pov[m];l++)for(int r=0;r<=min((l/pov[j])%5,k);r++){
		if(j==m-1){
			if(r!=k)continue;
			if(i==n-1)chmn(res,f[i][j][k][l]+(!!r)*c[i][j]);
			else chmn(f[i+1][0][a[i+1]][l-pov[j]*r],f[i][j][k][l]+(!!r)*c[i][j]);
		}else chmn(f[i][j+1][k-r][l-pov[j]*r],f[i][j][k][l]+(!!r)*c[i][j]);
	}
	printf("%d\n",res==0x3f3f3f3f?-1:res);
	return 0;
}