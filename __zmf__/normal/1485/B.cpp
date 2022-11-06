#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,q,k,a[100009],s[100009],l,r;
long long ans;
int main()
{
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	s[1]=a[2]-2;
	for(int i=2;i<n;i++)
	{
		s[i]=s[i-1]+(a[i+1]-a[i-1]-2);
	}
	s[n]=s[n-1]+k-a[n-1]-1;
	for(int i=1;i<=q;i++)
	{
		l=read(),r=read();
		if(l==r)
		{
			printf("%d\n",k-1);
			continue;
		}
		ans=s[r-1]-s[l];
		ans=ans+(a[l+1]-2);
		ans=ans+(k-a[r-1]-1);
		printf("%lld\n",ans);
	}
	return 0;
}