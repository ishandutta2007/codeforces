#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int l, r, m;
int A, B, C;

bool check(int n, int a)
{
	if(n == 0)
		return 0;
	A = a;
	int diff = m - n * a;
	if(abs(diff) > r - l)
		return 0;
	if(diff > 0)
		C = l, B = l + diff;
	else
		C = r, B = r - abs(diff);
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> l >> r >> m;
		for(int a = l; a <= r; a++)
		{
			int n = m / a;
			if(check(n, a))
			{
				cout << A << " " << B << " " << C << endl;
				break;
			}
			if(check(n + 1, a))
			{
				cout << A << " " << B << " " << C << endl;
				break;
			}
		}
	}
	return 0;
}