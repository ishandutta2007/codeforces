#include <iostream>
using namespace std;

long long n;
int main()
{
	cin>>n;
	long long i=1;
	while(1)
	{
		if(n-i<=0)
		{
			cout<<n<<endl;
			return 0;
		}
		n-=i;
		++i;
	}
}