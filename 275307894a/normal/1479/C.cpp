#include<cstdio>
using namespace std;
int n,m,k,l,r;
struct yyy{int x,y,z;}s[10039];
int main(){
	register int i,j;n=22;
	scanf("%d%d",&l,&r);printf("YES\n");r-=l;
	for(i=2;i<=n;i++)s[++m]={1,i,l};
	for(i=2;i<n;i++){
		for(j=i+1;j<n;j++) s[++m]={i,j,1<<i-2};
	}
	for(i=2;i<n;i++)if((r>>i-2)&1)s[++m]={i,n,((r>>i-1)<<i-1)+1};
	printf("%d %d\n",n,m);
	for(i=1;i<=m;i++) printf("%d %d %d\n",s[i].x,s[i].y,s[i].z);
}/////