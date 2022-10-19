#include<cstdio>
using namespace std;
int n;
double ans;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) ans+=1.0/i;
	printf("%.9lf",ans);
	return 0;
}