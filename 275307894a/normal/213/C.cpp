#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,f[2][339][339],ans,tot,pus,a[339][339],now1,now2,now,last;
int main() {
	register int i,j,k;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[1][1][1]=a[1][1];
	for(i=2; i<=2*n-1; i++) {
		now=i&1;last=now^1;
		for(j=1; j<=n; j++) {
			if(i-j+1>=1&&i-j+1<=n) {
				for(k=1; k<=n; k++) {
					if(i-k+1>=1&&i-k+1<=n){
						f[now][j][k]=-1e9;
						now1=i-j+1;now2=i-k+1;
						f[now][j][k]=max(f[now][j][k],max(f[last][j][k],f[last][j-1][k]));
						f[now][j][k]=max(f[now][j][k],max(f[last][j][k-1],f[last][j-1][k-1]));
						f[now][j][k]+=a[j][now1];
						if(j!=k) f[now][j][k]+=a[k][now2];
					}
				}
			}
		}
	}
	printf("%d\n",f[(n*2-1)&1][n][n]);
}