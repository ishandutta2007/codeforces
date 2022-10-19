#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string a,b;
int main()
{
	cin>>a;
	n=a.size();
	bool z=false;
	for(int i=n-1;i>=0;--i)
	{
		if(a[i]!='0')
			z=true;
		if(z)
			b+=a[i];
	}
	n=b.size();
	for(int i=0;i<n;++i)
		if(b[i]!=b[n-i-1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	return 0;
}