#include <iostream>
using namespace std;

long long n,a,b,p,q,ab;
long long gcd(long long x,long long y)
{
	if(x==0)
		return y;
	if(x>y)
		return gcd(y,x);
	return gcd(y%x,x);
}
long long ayb(long long x,long long y)
{
	return (x*y)/gcd(x,y);
}
int main()
{
	cin>>n>>a>>b>>p>>q;
	ab=ayb(a,b);
	if(p>q)
	{
		swap(a,b);
		swap(p,q);
	}
	cout<<(n/b)*q+(n/a-n/ab)*p<<endl;
	return 0;
}