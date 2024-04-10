#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,w[1000001],a,b,i;
__int64 Res,t,T;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		w[a]++,w[b]++;}
	for(i=1;i<=n;i++){
		t=w[i];Res+=t*(t-1);
		t=n-1-w[i];Res+=t*(t-1);
		T=w[i];Res-=t*T;
	}
	Res/=6;
	printf("%I64d\n",Res);
}