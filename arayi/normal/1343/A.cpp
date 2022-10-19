#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long int a,b,x,y,m,n;
int main() {
cin>>x;
for(int i=0;i<x;i++)
{
	cin>>n;m=4;
	for(int j=2;j<33;j++)
	{
		if(n%(m-1)==0)
		{
			y=n/(m-1);
			cout<<y<<endl;break;
		}m*=2;
	}
}
	return 0;
}