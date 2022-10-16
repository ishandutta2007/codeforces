#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;

	int n;
	cin>>n;
	int r1=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		r1=max(x,r1);
	}

	int m;
	cin>>m;
	int p1=INT_MIN;
	for (int i = 0; i < m; ++i)
	{
		cin>>x;
		p1=max(p1,x);
	}

	int k;
	cin>>k;
	int p2=INT_MAX;
	for (int i = 0; i < k; ++i)
	{
	    cin>>x;
		p2=min(p2,x);
	}

	int A,B;
	cin>>A>>B;
    
    double num=p1*B;
    double den=num+p2*A;
    double mul=num/den;
	double ans=r1*sqrt(mul);
	
	cout<<fixed;
	cout<<setprecision(12);
	cout<<ans;
	return 0;
}