#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,x,y,z,q[239][100039],a[100039],ans;
int main(){
	register int i,j;
	scanf("%d",&n);
	k=sqrt(n)/2;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=k;i++){
		for(j=n;j>=1;j--){
			if(j+a[j]+i>n) q[i][j]=1;
			else q[i][j]=q[i][j+a[j]+i]+1;
		} 
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(y>k){
			ans=0;
			while(x<=n)ans++,x=x+a[x]+y;
			printf("%d\n",ans);
		}
		else printf("%d\n",q[y][x]);
	}
}