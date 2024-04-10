#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,s=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s+=x;
		}
		if(s%n==0) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}