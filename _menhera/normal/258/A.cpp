#include<iostream>
#include<string>
using namespace std;
string a;
int main()
{
	cin>>a;
	int N=a.size();
	int i;
	if(N==1)
	{
		cout<<"0";
		return 0;
	}
	for(i=0;i<N-1;i++)
	{
		if(a[i]=='0' || i==N-1)break;
		cout<<a[i];
	}
	for(++i;i<N;i++)
	{
		cout<<a[i];
	}
	return 0;
}