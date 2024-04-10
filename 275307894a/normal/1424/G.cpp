#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,z,ans,maxn,tot,pus,x[100039],y[100039],head=1;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	sort(x+1,x+n+1);sort(y+1,y+n+1);
	for(i=1;i<=n;i++){
		ans++;
		while(head<=n&&y[head]<=x[i]) head++,ans--;
		if(ans>maxn) maxn=ans,pus=x[i];
	}
	printf("%d %d\n",pus,maxn);
}