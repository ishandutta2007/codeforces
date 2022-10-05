#include<cstdio>

int main(){
	register int T,n,a,b,f,u,v,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&a);
		f=0;
		for(i=2;i<=n;++i){
			scanf("%d",&b);
			if(a-b>=2||b-a>=2)f=1,u=i-1,v=i;
			a=b;
		}
		if(!f)puts("NO");
		else puts("YES"),printf("%d %d\n",u,v);
	}
	return 0;
}