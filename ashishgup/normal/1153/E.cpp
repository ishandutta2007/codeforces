#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 1005;
 
int query(int x1, int y1, int x2, int y2)
{
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int x;
	cin >> x;
	assert(x != -1);
	return x;
}
 
void report(int x1, int y1, int x2, int y2)
{
	cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	exit(0);
}
 
int n;
int r[N], c[N];
vector<int> oddRs, oddCs;
vector<pair<int, int> > ans;
 
void work()
{
	if(oddRs.size() == 2)
	{
		for(auto &it:oddRs)
		{
			int lo = 1, hi = n;
			while(lo < hi)
			{
				int mid = (lo + hi) / 2;
				if(query(it, 1, it, mid) % 2)
					hi = mid;
				else
					lo = mid + 1;
			}
			ans.push_back({it, lo});
		}
	}
	else
	{
		for(auto &it:oddCs)
		{
			int lo = 1, hi = n;
			while(lo < hi)
			{
				int mid = (lo + hi) / 2;
				if(query(1, it, mid, it) % 2)
					hi = mid;
				else
					lo = mid + 1;
			}
			ans.push_back({lo, it});
		}
	}
}
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		r[i] = query(i, 1, i, n);
		if(r[i] % 2)
			oddRs.push_back(i);
	}
	if(oddRs.size() % 2)
		oddRs.push_back(n);
	for(int i = 1; i <= n - 1; i++)
	{
		c[i] = query(1, i, n, i);
		if(c[i] % 2)
			oddCs.push_back(i);
	}
	if(oddCs.size() % 2)
		oddCs.push_back(n);
	work();
	report(ans[0].first, ans[0].second, ans[1].first, ans[1].second);
	return 0;
}