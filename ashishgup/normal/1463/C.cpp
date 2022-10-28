#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

struct data
{
	int st, ed, x1, x2;

	data(int _st, int _ed, int _x1, int _x2)
	{
		st = _st, ed = _ed, x1 = _x1, x2 = _x2;
	}
};

int n;
int tim[N], x[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> tim[i] >> x[i];
		int cur = 0;
		vector<data> v;
		v.push_back(data(0, 0, 0, 0));
		for(int i = 1; i <= n; i++)
		{
			if(tim[i] >= v.back().ed)
			{
				int curx = v.back().x2;
				int nextx = x[i];
				v.push_back(data(tim[i], tim[i] + abs(nextx - curx), curx, nextx));
			}
		}
		int ans = 0;
		int idx = 0;
		tim[n + 1] = 4e9;
		for(int i = 1; i <= n; i++)
		{
			while(tim[i] >= v[idx].ed && idx + 1 < v.size() && v[idx + 1].st >= tim[i])
				idx++;
			int reqdx = x[i];
			int x1 = v[idx].x1;
			int x2 = v[idx].x2;
			if(reqdx < min(x1, x2) || reqdx > max(x1, x2))
				continue;
			if(x2 >= x1)
			{
				int mnT = reqdx - x1;
				int mxT = reqdx - x1;
				int t1 = tim[i] - v[idx].st;
				int t2 = tim[i + 1] - v[idx].st;
				int T1 = max(t1, mnT);
				int T2 = min(t2, mxT);
				if(T2 >= T1)
					ans++;
			}
			else
			{
				int mnT = x1 - reqdx;
				int mxT = x1 - reqdx;
				int t1 = tim[i] - v[idx].st;
				int t2 = tim[i + 1] - v[idx].st;
				int T1 = max(t1, mnT);
				int T2 = min(t2, mxT);
				if(T2 >= T1)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}