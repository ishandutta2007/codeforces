#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int f[539][539],x,y,n,m,k,a[539];
int main(){
	register int i,j,k;
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),f[i][i]=1,f[i-1][i]=1+(a[i]==a[i-1]?0:1);
	for(i=n-1;i>=1;i--){
		for(j=i+2;j<=n;j++){
			if(a[i]==a[j]) f[i][j]=f[i+1][j-1];
			for(k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	}
	printf("%d\n",f[1][n]);
}