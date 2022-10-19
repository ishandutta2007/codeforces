#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,k;
		long long r1=1,r2=0;
		cin>>x>>y>>k;
		long long bz=(1ll*k*y-2)/(x-1)+1;
		if(1ll*k*y-1<=0)bz=0;
		r1+=bz*(x-1);
		r1-=1ll*k*y,r2+=k;
		long long bz2=(k-r1-1)/(x-1)+1;
		if(k-r1<=0)bz2=0;
		cout<<bz+k+bz2<<endl;
	}
	return 0;
}