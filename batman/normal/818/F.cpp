#include <bits/stdc++.h>
using namespace std;
int q;
int main()
{
	cin>>q;
	while(q--)
	{
		long long n,x,y;
		cin>>n;
		if(n==1){cout<<"0\n";continue;}
		double ex=2*n+1;
		ex-=sqrt((double)8*n+1);
		ex/=2;
		x=ex,y=x+1;
		cout<<max(min(2*x,(n-x)*(n-x-1)/2+x),min(2*y,(n-y)*(n-y-1)/2+y))<<"\n";
	}
	return 0;
}