#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double p;
	cin>>n>>p;
	for(int i=0;i<=n;i++)
	{
		double x=i*(i-1)*(i-2)/6+i*(i-1)/2*(n-i)+1.0/2*i*(n-i)*(n-i-1)/2;
		if(x>=p*n*(n-1)*(n-2)/6)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}