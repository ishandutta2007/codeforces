#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int x,y;
	bool operator<(const apple &other)const
	{
		if(y==other.y)return x<other.x;
		return y>other.y;
	}
}e[200005];
int a[200005],b[200005],d[200005];
int main()
{
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		e[i].x=a[i],e[i].y=a[i]-i;
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)if(e[i].y<=0)b[++m]=e[i].x;
	if(m==0)cout<<0<<endl;
	else
	{
		int l=0;
		for(int i=1;i<=m;i++)
		{
			if(l==0||b[i]>d[l])d[++l]=b[i];
			else d[lower_bound(d+1,d+l+1,b[i])-d]=b[i];
		}
		cout<<l<<endl;
	}
	return 0;
}