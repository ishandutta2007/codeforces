#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,c;
int main()
{
	cin>>n>>m>>a>>b;
	c=n/m;
	c*=m;
	cout<<min((n-c)*b,(c+m-n)*a);
	return 0;
}