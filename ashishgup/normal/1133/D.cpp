#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans = 0;
int a[N], b[N];
map<pair<int, int>, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			ans += (b[i] == 0);
		else
		{
			int num = -b[i];
			int den = a[i];
			int store = __gcd(abs(num), abs(den));
			num /= store;
			den /= store;
			if(den < 0)
				num *= -1, den *= -1;
			if(num == 0)
				den = 0;
			m[{num, den}]++;
		}
	}
	int mx = 0;
	for(auto &it:m)
		mx = max(mx, it.second);
	ans += mx;
	cout<<ans;
	return 0;
}