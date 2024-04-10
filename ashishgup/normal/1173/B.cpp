#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, m;
 
int32_t main()
{
	IOS;
	cin >> n;
	m = n / 2 + 1;
	cout << m << endl;
	for(int i = 1; i <= m; i++)
		cout << 1 << " " << i << endl;
	for(int i = m + 1; i <= n; i++)
		cout << m << " " << i - m + 1 << endl;
	return 0;
}