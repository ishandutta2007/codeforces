#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, r;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> r;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int shift = 0, ans = 0;
		for(int i = n; i >= 1;)
		{
			if(a[i] - shift <= 0)
				break;
			ans++;
			shift += r;
			int j = i;
			while(a[j] == a[i])
				j--;
			i = j;
		}
		cout << ans << endl;
	}
	return 0;
}