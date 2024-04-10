#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m;
int p[N], q[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 0; i <= n; i++)
		cin >> p[i];
	for(int i = 0; i <= m; i++)
		cin >> q[i];
	if(n < m)
		cout << "0/1";
	else if(n > m && (double)p[0] / q[0] > 0)
		cout << "Infinity";
	else if(n > m && (double)p[0] / q[0] < 0)
		cout << "-Infinity";
	else
	{
		int num = p[0];
		int den = q[0];
		int cur = __gcd(num, den);
		num /= cur;
		den /= cur;
		if(den < 0)
			num *= -1, den *= -1;
		cout << num << "/" << den;
	}
	return 0;
}