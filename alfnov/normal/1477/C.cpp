#include<bits/stdc++.h>
using namespace std;
int x[5005],y[5005],q[5005];
bool ok(int a,int b,int c)
{
	if(a==0||c==0)return 1;
	return 1ll*(x[a]-x[b])*(x[b]-x[c])+1ll*(y[a]-y[b])*(y[b]-y[c])<0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	q[1]=1,q[2]=2;
	for(int i=3;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=i;j++)
		if((j==1||ok(q[j-2],q[j-1],i))&&ok(q[j-1],i,q[j])&&ok(i,q[j],q[j+1]))
		{
			flag=1;
			for(int k=i-1;k>=j;k--)q[k+1]=q[k];
			q[j]=i;
			break;
		}
		if(!flag)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",q[i]);
	return 0;
}