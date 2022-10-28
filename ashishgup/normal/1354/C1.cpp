#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 1e5 + 5;

int n;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		double o, h;
		o = 0.5l;
		double theta = acosl(-1.0l) / (2 * n);
		h = o / tan(theta);
		cout << fixed << setprecision(12) << 2 * h << endl;
	}
	return 0;
}