#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 4005;

int n;
int a[N], valid[N];
vector<int> v;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	valid[0] = 1;
	while(t--)
	{
		v.clear();
		cin >> n;
		int mx = 0, ct = 0;
		for(int i = 1; i <= 2 * n; i++)
		{
			valid[i] = 0;
			cin >> a[i];
			if(i == 1)
				mx = max(mx, a[i]);
			if(a[i] > mx)
			{
				v.push_back(ct);
				mx = a[i], ct = 1;
			}
			else
				ct++, mx = max(mx, a[i]);
		}
		v.push_back(ct);
		for(auto &it:v)
		{
			int cur = it;
			for(int i = n; i >= cur; i--)
				if(valid[i - cur])
					valid[i] = 1;
		}
		if(valid[n])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}