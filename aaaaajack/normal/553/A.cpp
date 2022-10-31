#include<cstdio>
#include<cstring>
#define Q 1000000007
using namespace std;
int a[1010],c[1010][1010];
int cmb(int n,int m){
	if(n<m||m<0) return 0;
	if(n==m||m==0) return 1;
	if(c[n][m]>=0) return c[n][m];
	return c[n][m]=(cmb(n-1,m)+cmb(n-1,m-1))%Q;
}
int main(){
	memset(c,-1,sizeof(c));
	int k,sum=0,ans=1;
	scanf("%d",&k);
	for(int i=0;i<k;i++) scanf("%d",&a[i]);
	for(int i=0;i<k;i++){
		ans=1LL*ans*cmb(sum+a[i]-1,sum)%Q;
		sum+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}