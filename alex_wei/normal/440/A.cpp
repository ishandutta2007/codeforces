#include<bits/stdc++.h>
using namespace std;
long long n,s,a; 
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>a,s+=a;
	cout<<n*(n+1)/2-s;
	return 0;
}