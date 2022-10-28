#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

int32_t main()
{
	IOS;
	int a, b, c, n;
	cin>>a>>b>>c>>n;
	a-=c;
	b-=c;
	if(a<0 || b<0 || a+b+c>=n)
		cout<<"-1";
	else
		cout<<n - (a+b+c);
}