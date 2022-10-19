#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	if (k==1 && n>1){
		cout<<"-1\n";
		return 0;
	}
	
	if (k>n){
		cout<<"-1\n";
		return 0;
	}
	
	if (k==1 && n==1){
		cout<<"a\n";
		return 0;
	}
	
	n-=(k-2);
	
	for (int i=0; i<n; ++i)
	if (i%2==0)
	cout<<"a";
	else
	cout<<"b";
	
	for (int i=2; i<k; ++i){
		char ch='a'+i;
		cout<<ch;
	}
	
	cout<<"\n";
	
	return 0;
}