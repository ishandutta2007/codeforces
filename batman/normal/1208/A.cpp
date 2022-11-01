#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define ld long double
#define N ((int)501*1000)

int t,a,b,n;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		if(n%3==0)cout<<a<<"\n";
		else if(n%3==1)cout<<b<<"\n";
		else cout<<(a^b)<<"\n";
	}
	return 0;
}