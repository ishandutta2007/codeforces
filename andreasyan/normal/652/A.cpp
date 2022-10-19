#include <iostream>
using namespace std;

int h1,h2,a,b;
int main()
{
	//in
	cin>>h1>>h2>>a>>b;
	////
	if(h1+(22-14)*a>=h2)
	{
		cout<<0<<endl;
		return 0;
	}
	h1+=(22-14)*a;
	h1-=(2+10)*b;
	////
	int h=(22-10)*a;
	int i=(2+10)*b;
	////
	if(h<=i)
	{
		if(h1+h>=h2)
			cout<<1<<endl;
		else
			cout<<-1<<endl;
		return 0;
	}
	int n=(h2-h1-i)/(h-i)+!!((h2-h1-i)%(h-i));
	cout<<n<<endl;
	return 0;
}