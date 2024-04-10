#include <iostream>
using namespace std;

int m;
long long n;
long long ans;
int main()
{
	int j;
	long long k;
	cin>>m;
	for(j=0;j<m;++j)
	{
		cin>>n;
		ans=(1+n)*n/2;
		k=1;
		while(k<=n)
		{
			ans-=2*k;
			k*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}