#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
long long int a[1000000],x,y,m,n,l;
stack <long long int> b;
int main() {
cin>>x;
for(int j=0;j<x;j++)
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b.push(a[0]);
	for(int i=1;i<n;i++)
	{
		y=b.top();
		if((a[i]>0&&y<0)||(a[i]<0&&y>0))
		{
			b.push(a[i]);
		}
		else
		{
			if(a[i]>y)
			{
				b.pop();b.push(a[i]);
			}
		}
	}
while(!b.empty())
{
	l+=b.top();
	b.pop();
}
	
	cout<<l<<endl; l=0;
}
	return 0;
}