#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a0,a1,a2;
		int b0,b1,b2;
		cin>>a0>>a1>>a2;
		cin>>b0>>b1>>b2;
		cout<<(-2*max(0,b2-max(0,a2-b1)-a0)+2*min(a2,b1))<<endl;
	}
	return 0;
}