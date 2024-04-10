#include <iostream>
#include <set>
using namespace std;

set<long long> a;
int main()
{
	long long n,k;
	cin>>n>>k;
	k=min(k,long long(1000000));
	for(long long i=1;i<=k;++i)
	{
		if(a.find(n%i)!=a.end())
		{
			cout<<"No"<<endl;
//			system("pause");
			return 0;
		}
		a.insert(n%i);
	}
	cout<<"Yes"<<endl;
//	system("pause");
	return 0;
}