#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int l,r,n,k,mid,a[200009],sum[200009];
inline bool check(int p)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=p)sum[i]=1;
		else sum[i]=-1;
	}
	for(int i=2;i<=n;i++)
		sum[i]+=sum[i-1];
	//for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
	int now_min=0;
	for(int i=k;i<=n;i++)
	{
		if(now_min<sum[i])return 1;
		now_min=min(now_min,sum[i-k+1]);
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	a[1]=read(),l=a[1],r=a[1];
	for(int i=2;i<=n;i++)a[i]=read(),l=min(l,a[i]),r=max(r,a[i]);
	//if(check(3))cout<<"qwq"<<endl;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl;
		mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}