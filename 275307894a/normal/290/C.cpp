#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[10039],foo,bar,baz,quz=1,pur;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&pur);
		foo=foo+pur;bar++;
		if(foo*quz>baz*bar) baz=foo,quz=bar;
	}
	printf("%lf\n",baz*1.0/quz);
}