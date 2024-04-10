#include <iostream>
using namespace std;

long long n;
long long evk(long long a,long long b)
{
	if(!b)
		return a;
	else
	{
		n+=a/b;
		return evk(b,a%b);
	}
}
int main()
{
	long long a,b;
	cin>>a>>b;
	evk(a,b);
	cout<<n<<endl;
	return 0;
}