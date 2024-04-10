#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	cin>>n>>k;
	if(n==k)
		return cout<<-1,0;
	for(int i=2;i<=n-k;i++)cout<<i<<" ";
	cout<<"1 ";
	for(int i=n-k+1;i<=n;i++)cout<<i<<" ";	
    return 0;
}