#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int res;
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		cout<<1<<endl;
		fflush(stdout);
		cin>>res;
		if(res==0)
			return 0;
		a[i]=res;
	}
	int l=2,r=m;
	for(int i=1;i<=60;i++)
	{
		int m=(l+r)/2;
		cout<<m<<endl;
		fflush(stdout);
		cin>>res;
		if(res==0)
			return 0;
		else if(res*a[(i-1)%n+1]==1)
			l=m+1;
		else
			r=m-1;
	}
	return 0;
}