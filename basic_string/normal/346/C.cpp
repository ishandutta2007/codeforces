#include<cstdio>
#include<algorithm>
int a[100009],pr[100009],ne[100009];
int main(){
	int n,i,p,q,j,k,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	std::sort(a+1,a+n+1),n=std::unique(a+1,a+n+1)-a-1;
	scanf("%d%d",&p,&q),pr[n+1]=n,ne[0]=1;
	for(i=1;i<=n;++i)pr[i]=i-1,ne[i]=i+1;
	while(p>q){
		j=1;
		for(i=ne[0];i<=n;i=ne[i]){
			k=p%a[i];
			if(p-k<q)pr[ne[i]]=pr[i],ne[pr[i]]=ne[i];
			else if(k>j)j=k;
		}
		p-=j,++s;
	}
	printf("%d",s);
	return 0;
}