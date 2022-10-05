#include<cstdio>
int main(){
	register int i,t,n;
	register long long s,u,w,a,p;
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&s),u=w=0;
		for(i=1;i<=n;++i){
			scanf("%lld",&p),w+=p;
			if(w-u>s&&w-p>s)break;
			if(u<p)u=p,a=i;
		}
		if(w<=s)printf("%d\n",0);
		else printf("%lld\n",a);
		for(++i;i<=n;++i)scanf("%*lld");
	}
	return 0;
}