#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
string s[N], t[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < m; i++)
		cin >> t[i];
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		x--;
		cout << s[x % n] << t[x % m] << endl; 
	}
	return 0;
}