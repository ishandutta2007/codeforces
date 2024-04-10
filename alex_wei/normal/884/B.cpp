#include<bits/stdc++.h>
using namespace std;
long long n,l,k,s;
int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)cin>>k,s+=k;
	s+=n-1;
	if(s==l)cout<<"YES";
	else cout<<"NO";
	return 0;
}