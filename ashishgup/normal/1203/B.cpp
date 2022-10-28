#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
int a[4 * N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		map<int, int> m;
		cin >> n;
		for(int i = 1; i <= 4 * n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		sort(a + 1, a + 4 * n + 1);
		bool check = 1;
		set<int> s;
		for(int l = 1, r = 4 * n; l <= r; l += 2, r -= 2)
		{
			int cur = (a[l] == a[l + 1]);
			int cur2 = (a[r] == a[r - 1]);
			check &= cur;
			check &= cur2;
			if(!check)
				break;
			int area = (a[l] * a[r]);
			s.insert(area);
		}
		if(check && s.size() == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}