#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		char ch = 'a';
		string ans = "";
		for(int i = 1; i <= b; i++)
		{
			ans += ch;
			if(i != b)
				ch++;
		}
		for(int i = b + 1; i <= a; i++)
			ans += ch;
		for(int i = a; i < n; i++)
			ans += ans[i - a];
		cout << ans << endl;
	}
	return 0;
}