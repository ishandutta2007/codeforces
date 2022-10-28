#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int ans[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if((n / 2) % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		vector<int> v = {2, 4, 1, 5};
		int inc = 0;
		for(int i = 1, j = n; i <= j;)
		{
			ans[i] = v[0] + inc;
			ans[i + 1] = v[1] + inc;
			ans[j] = v[2] + inc;
			ans[j - 1] = v[3] + inc;
			inc += 6;
			i += 2;
			j -= 2;
		}
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}