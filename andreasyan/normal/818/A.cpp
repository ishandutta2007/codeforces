#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long n,m;
int main()
{
	cin>>n>>m;
	long long x=(n/2)/(m+1);
	cout<<x<<' '<<m*x<<' '<<n-x-m*x<<endl;
//	system("pause");
	return 0;
}