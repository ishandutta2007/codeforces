#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[539][539];
char a[539],_s;
int main(){
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		_s=getchar();
		while(_s<'a'||_s>'z') _s=getchar();
		a[i]=_s;
	}
	for(i=1;i<=n;i++) f[i][i]=1;
	for(i=n;i>=1;i--){
		for(j=i+1;j<=n;j++){
			f[i][j]=1e9;
			for(k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j-1]+1-(a[j]==a[k]?1:0));
		}
	}
	printf("%d\n",f[1][n]);
}