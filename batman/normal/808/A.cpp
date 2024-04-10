#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	ll n2=n;
	vector <ll> ex;
	while(n)ex.push_back(n%10),n/=10;
		ll num=ex.back()+1;
		for(int i=0;i<(ll)ex.size()-1;i++)num*=10;
	cout<<num-n2<<"\n";
	return 0;
}