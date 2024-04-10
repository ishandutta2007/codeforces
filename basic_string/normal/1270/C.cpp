#include<cstdio>
int main(){
	register int T,n;
	register long long i,u,v;
	scanf("%lld",&T);
	while(T--){
		u=v=0;
		scanf("%d",&n);
		while(n--)scanf("%lld",&i),u+=i,v^=i;
		u+=v;
		printf("2\n%lld %lld\n",v,u);
	}
	return 0;
}