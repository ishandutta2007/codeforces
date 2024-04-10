#include <iostream>
using namespace std;

long long a,b;
long long ans=1;
int main()
{
	cin>>a>>b;
	for(long long i=b;i>a;--i)
	{
		if(i%10==0)
		{
			cout<<'0'<<endl;
//			system("pause");
			return 0;
		}
		ans=(ans*(i%10))%10;
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}