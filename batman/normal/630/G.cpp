#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (40)

ll n;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ll res1=n*(n+1)*(n+2)*(n+3)*(n+4)/120;
	ll res2=n*(n+1)*(n+2)/6;
	cout<<res1*res2;
	return 0;
}