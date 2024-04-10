#include <iostream>
#include <vector>
using namespace std;
#define ll long long


ll a,b;
int main() {
	cin>>a>>b;
	if(b>a)
		a=b;
	a=6-a+1;
	b=6;
	if(a%2==0)
		a/=2,b/=2;
	if(a%3==0)
		a/=3,b/=3;
	cout<<a<<"/"<<b<<endl;			
	
						
	return 0;
}