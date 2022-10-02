#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		char a,b;
		cin >> a >> b;
		a-='a',b-='a';
		int ans=a*25;
		if(b<a) cout << ans+b+1;
		else cout << ans+b;
		cout << "\n";
	}
	return 0;
}