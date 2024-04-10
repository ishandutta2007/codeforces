#include<bits/stdc++.h>
using namespace std;
long long n,a,x,y,z; 
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a,x+=a;
	for(int i=1;i<n;i++)
		cin>>a,y+=a;
	for(int i=2;i<n;i++)
		cin>>a,z+=a;
	cout<<x-y<<" "<<y-z;
	return 0;
}