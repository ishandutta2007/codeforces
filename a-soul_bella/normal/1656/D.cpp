#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
map <int,int> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n==(n&(-n))) cout << "-1\n";
		else cout << min(n/(n&-n),(n&-n)*2) << "\n";
	}
	return 0;
}