#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[100039];
int main(){
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	register int i;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(i=x;i<=n;i++) f[i]=f[i-x]+1;
	for(i=y;i<=n;i++) f[i]=max(f[i],f[i-y]+1);
	for(i=z;i<=n;i++) f[i]=max(f[i],f[i-z]+1);
	printf("%d\n",f[n]);
}