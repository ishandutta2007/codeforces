//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,now,maxn,mid,res;
inline int query(int u,int l,int r,int flag)
{
	printf("1 %d %d ",r-l+1-flag,u);
	for(int i=l;i<=r;i++)
		if(flag==0||i!=u)printf("%d ",i);
	puts("");
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		maxn=query(1,2,n,0);
		int l=2,r=n;
		while(l<r)
		{
			mid=(l+r)/2;
			now=query(1,l,mid,0);
			if(now==maxn)r=mid;
			else l=mid+1;
		}
		maxn=query(l,1,n,1);
		cout<<-1<<" "<<maxn<<endl;
	}
	return 0;
}