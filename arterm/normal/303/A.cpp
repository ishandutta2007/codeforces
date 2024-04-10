#include <iostream>

using namespace std;

int n;

int main()
{
	cin>>n;
	if (n%2==0){
		cout<<"-1\n";
		return 0;
	}
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<i;
	cout<<"\n";
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<i;
	cout<<"\n";
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<((2*i)%n);
	cout<<"\n";
	return 0;
}