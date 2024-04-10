//12.31
#include<cstdio>
long long a[100009];
int main(){
	register long long t,n,m,x,u,v,w,i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m),u=v=w=0;
		for(i=1;i<=n;++i)scanf("%lld",&x),a[x]=i;
		for(i=1;i<=m;++i){
			scanf("%lld",&x),--u;
			if(a[x]>v){
				u+=a[x]-v;
				w+=u<<1;
				v=a[x];
			}
		}
		printf("%lld\n",w+m);
	}
	return 0;
}