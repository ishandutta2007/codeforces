#include <iostream>

using namespace std;

int a,b,r=0;

int main()
{
	cin>>a>>b;
	int s=0;
	while (a){
		s+=a;
		r+=a;
		a=r/b;
		r%=b;
	}
	cout<<s<<"\n";
	return 0;
}