#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int m1,m2;
	apple(int m1=INT_MIN,int m2=INT_MIN):m1(m1),m2(m2){}
}b[1<<21];
apple operator*(apple a,int x)
{
	return apple(max(a.m1,x),max(a.m2,min(a.m1,x)));
}
apple operator+(apple a,apple b)
{
	return apple(max(a.m1,b.m1),max(min(a.m1,b.m1),max(a.m2,b.m2)));
}
int a[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=b[a[i]]*i;
	int B=21,A=1<<B;
	for(int i=2;i<=A;i<<=1)for(int j=0;j<A;j+=i)
		for(int k=j;k<j+(i>>1);k++)b[k]=b[k]+b[k+(i>>1)];
	int ans=0;
	for(int i=1;i<=n-2;i++)
	{
		int ss=0,aa=0;
		for(int j=B-1;j>=0;j--)
		{
			if(!(a[i]&(1<<j)))
			{
				if(b[ss|(1<<j)].m2>i)aa|=(1<<j),ss|=(1<<j);
			}else aa|=(1<<j);
		}
		ans=max(ans,aa);
	}
	cout<<ans<<endl;
	return 0;
}