#include<cstdio>
using namespace std;
int n,x,y,m,k,a[200039],q[200039];
int main(){
	register int i;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[x]++;a[y+1]--;
	}
	for(i=1;i<=200001;i++) a[i]+=a[i-1];
	for(i=1;i<=200001;i++) q[i]=a[i]>=k?1:0;
	for(i=1;i<=200001;i++) q[i]+=q[i-1];
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",q[y]-q[x-1]);
	}
}