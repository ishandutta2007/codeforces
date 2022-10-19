#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long int a,b,x,y,m,n;
int main() {
cin>>x;
for(int i=0;i<x;i++)
{
	cin>>n;
	if((n/2)%2==1)
	{
		cout<<"NO"<<endl;
	}
	else
	{cout<<"YES"<<endl;
	    y=0;
	  m=2;
	while(y!=n/2)
	{   b+=m; 
		cout<<m<<" ";
		m+=2;
		y++;
		
	}
	y=0;
	m=1;
	while(y!=(n/2)-1)
	{a+=m;
		cout<<m<<" ";
		m+=2;
		y++;
		
	}
	cout<<b-a<<endl;b=0;a=0;
	}
}
	return 0;
}