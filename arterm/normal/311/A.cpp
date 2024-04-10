#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if (n*(n-1)/2<=k){
		cout<<"no solution\n";
		return 0;
	}
	
	for (int i=0; i<n-2; ++i)
	cout<<"0 "<<10*i<<"\n";
	
	cout<<"9 -100000000\n";
	cout<<"9 -100000002\n";
	return 0;
}