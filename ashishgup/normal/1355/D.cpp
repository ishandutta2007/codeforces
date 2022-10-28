#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	if(s >= 2 * n)
	{
		cout << "YES" << endl;
		for(int i = 1; i <= n - 1; i++)
			cout << 2 << " ";
		cout << s - 2 * (n - 1);
		cout << endl;
		cout << 1;
	}
	else
		cout << "NO";
	return 0;
}