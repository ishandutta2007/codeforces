#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
int main()
{
	cin>>n;
	for(ll i=1;i<=2e6;i++)
		if(n>=i*(i+1)/2*3-i && n%3==((-i)%3+3)%3)
			ans++;
	cout<<ans;		
    return 0;
}