#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N ((ll)301*1000)

ll k,a,b;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k>>a>>b;
	if(a/k==0 && b/k==0)return cout<<-1,0;
	if(b/k>0 && a/k>0)return cout<<a/k+b/k,0;
	if(a/k==0 && b%k==0)return cout<<b/k,0;
	if(b/k==0 && a%k==0)return cout<<a/k,0;
	cout<<-1;
	return 0;
}