#include <iostream>

#define long long long

using namespace std;



int main()
{
	long a,b,ans=0;
	cin>>a>>b;
	while (a!=0){
		ans+=b/a;
		b%=a;
		swap(a,b);
	}
	cout<<ans<<"\n";
	return 0;
}