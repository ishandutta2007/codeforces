#include <iostream>
#include <algorithm>
using namespace std;
const int N=1002;

int a[N];
int n;
int main()
{
	int i, j;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0, j=n-1; i<j;++i,--j)
	{
		cout<<a[i]<<' '<<a[j]<<' ';
	}
	if(n%2==1)
		cout<<a[i];
	cout<<endl;
	return 0;
}