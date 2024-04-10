#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, a, b, p, q;

int32_t main()
{
	IOS;
	cin>>n>>a>>b>>p>>q;
	int storelcm=lcm(a, b);
	int ans=(n/a)*p + (n/b)*q - (n/storelcm)*min(p, q);
	cout<<ans;
	return 0;
}