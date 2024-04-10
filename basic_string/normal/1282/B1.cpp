#include<cstdio>
#include<algorithm>
int a[200009];//
int main(){
	register int t,n,p,k,i,j,u,v,w;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&p,&k),u=w=0;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		std::sort(a+1,a+n+1);
		for(i=0;i<k;++i){
			u+=a[i],v=u,j=i+k;
			if(v>p)break;
			while(j<=n&&v+a[j]<=p)v+=a[j],j+=k;
			j-=k,w=w>j?w:j;
		}
		printf("%d\n",w);
	}
	return 0;
}