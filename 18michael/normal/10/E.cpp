#include<bits\stdc++.h>
#define inf 0x7f7f7f7f
int n,t,cnt,res,ans=inf,a[402];
inline int G(int x)
{
	int t=0;
	for(int i=1;i<=n;++i)t+=x/a[i],x%=a[i];
	return t;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			t=a[i-1]-1,cnt=0,res=0;
			for(int k=1;k<=j;++k)cnt+=t/a[k],res+=(t/a[k])*a[k],t%=a[k];
			if(cnt+1<G(res+=a[j]))ans=std::min(ans,res);
		}
	return 0&printf("%d",ans==inf? -1:ans);
}