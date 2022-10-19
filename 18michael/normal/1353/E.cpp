#include<cstdio>
#define inf 0x3f3f3f3f
int n,k,sum,res,ans,mx,mn,Test_num;
int pre[1000002]={};
char s[1000002];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d%s",&n,&k,s),sum=0,ans=inf;
		for(int i=0;i<n;++i)sum+=(s[i]^48);
		for(int i=0;i<k;++i)
		{
			res=inf,mn=mx=0;
			for(int j=i;j<n;j+=k)pre[j/k+1]=pre[j/k]+(s[j]^48);
			for(int j=i;j<n;j+=k)pre[j/k+1]=((pre[j/k+1]<<1)-(j/k+1));
			for(int j=i;j<n;j+=k)mx=max(mx,pre[j/k+1]),mn=min(mn,pre[j/k+1]),res=min(res,sum-pre[j/k+1]+mn);
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}