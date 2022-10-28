#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, sx, sy;
int x[N], y[N];
vector<pair<int, int> > cand;

int32_t main()
{
	IOS;
	cin >> n >> sx >> sy;
	cand.push_back({sx + 1, sy});
	cand.push_back({sx, sy + 1});
	cand.push_back({sx, sy - 1});
	cand.push_back({sx - 1, sy});
	vector<int> sum(4, 0);
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		int mnx = min(sx, x[i]);
		int mxx = max(sx, x[i]);
		int mny = min(sy, y[i]);
		int mxy = max(sy, y[i]);
		for(int j = 0; j < 4; j++)
		{
			if(cand[j].first >= mnx && cand[j].first <= mxx && cand[j].second >= mny && cand[j].second <= mxy)
			{
				sum[j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 4; i++)
		ans = max(ans, sum[i]);
	cout << ans << endl;
	for(int i = 0; i < 4; i++)
	{
		if(sum[i] == ans && cand[i].first >= 0 && cand[i].first <= 1e9 && cand[i].second >= 0 && cand[i].second <= 1e9)
		{
			cout << cand[i].first << " " << cand[i].second;
			return 0;
		}
	}
	return 0;
}