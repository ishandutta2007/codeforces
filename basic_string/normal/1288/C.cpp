#include<bits/stdc++.h>
using namespace std;
const long long P=1e9+7;
long long c[1234][13];
int main(){
	register int i,j,n,m;
	register long long s=0;
	scanf("%d%d",&n,&m),c[0][0]=1;
	for(i=1;i<=1200;++i){
		c[i][0]=1;
		for(j=1;j<=m;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
		}
	}
	for(i=1;i<=n;++i){
		s=(s+(c[i+m-1][m]+P-c[i+m-2][m])*c[n-i+m][m])%P;
	}
	printf("%lld",s);
	return 0;
}//