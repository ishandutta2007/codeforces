#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	if(k<=n)
		cout<<(k-1)/2<<endl;
	else
	{
		cout<<max(0ll,n-k/2)<<endl;
	}
	return 0;
}