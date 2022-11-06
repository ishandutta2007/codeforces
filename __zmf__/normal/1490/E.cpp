#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,ans[200009];
long long sum,pos;
struct point
{
	int id,val;
}a[200009];
inline bool cmp(point xxx,point yyy)
{
	return xxx.val<yyy.val;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		sum=0,pos=0;
		n=read();
		for(int i=1;i<=n;i++)a[i].val=read(),a[i].id=i;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n;i++)
		{
			sum+=a[i].val;
			if(sum<a[i+1].val)pos=i;
		}
		printf("%d\n",n-pos);
		for(int i=pos+1;i<=n;i++)ans[i-pos]=a[i].id;
		sort(ans+1,ans+n-pos+1);
		for(int i=1;i<=n-pos;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}