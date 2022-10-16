#include<bits/stdc++.h>
using namespace std;
int t,x;
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>x>>x,cout<<(x-x%2)/2<<" "<<x-x%2<<endl;
	return 0;
}