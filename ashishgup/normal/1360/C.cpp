#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		map<int, int> f;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			f[a[i] % 2]++;
		}
		int ans = 1;
		for(auto &it:f)
			ans &= (it.second % 2 == 0);
		if(ans)
			cout << "YES" << endl;
		else
		{
			sort(a + 1, a + n + 1);
			for(int i = 1; i + 1 <= n; i++)
				ans |= (a[i + 1] - a[i] == 1);
			if(ans)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}	
	return 0;
}