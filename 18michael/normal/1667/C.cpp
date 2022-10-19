#include<cstdio>
int n;
int main()
{
	scanf("%d",&n),printf("%d\n",(2*n+1)/3);
	if(n==1)return 0&puts("1 1");
	while((n%3)^2)printf("%d %d\n",n,n),--n;
	for(int i=1;i<=(n+1)/3;++i)printf("%d %d\n",i,(n+4)/3-i);
	for(int i=1;i<=(n-2)/3;++i)printf("%d %d\n",n+1-i,n-(n-2)/3+i);
	return 0;
}//