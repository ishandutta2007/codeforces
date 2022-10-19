#include<cstdio>
#define LL long long
int n,k,d,res[1002];
int F(LL x){return x<n? x:n;}
int main()
{
	scanf("%d%d%d",&n,&k,&d),res[d]=1;
	for(int i=d-1;~i;--i)res[i]=F(1LL*res[i+1]*k);
	if(res[0]<n)return 0&puts("-1");
	for(int i=1;i<=d;++i)for(int j=1;j<=n;++j)printf("%d%c",((j-1)/res[i])%k+1,j==n? '\n':' ');
	return 0;
}