#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int s=a+b+c;
		if(s%3==0) cout << "0\n";
		else cout << 1 << "\n";
	}
	return 0;
}