#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int g = 0;
	for(int i = 1; i <= n; i++)
			g = __gcd(g, a[i]);
	int cnt = a[n] / g - n;
	if(cnt % 2)
		cout << "Alice";
	else
		cout << "Bob";
	return 0;
}