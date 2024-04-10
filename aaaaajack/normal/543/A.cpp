#include<cstdio>
#include<cstring>
#define N 510
using namespace std;
int r[N][N];
int main(){
	int m,b,a[N],n,i,j,k,Q,ans=0;
	scanf("%d%d%d%d",&n,&m,&b,&Q);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	r[0][0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<=b-a[i];k++){
				r[j+1][k+a[i]]=(r[j+1][k+a[i]]+r[j][k])%Q;
			}
		}
	}
	for(i=0;i<=b;i++){
		ans=(ans+r[m][i])%Q;
	}
	printf("%d\n",ans);
	return 0;
}