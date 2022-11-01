#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)



int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;cin>>n;n++;
	if(n==1)cout<<"0\n";
	else if(n%2)cout<<n<<"\n";
	else cout<<n/2<<"\n";
	
	return 0;
}