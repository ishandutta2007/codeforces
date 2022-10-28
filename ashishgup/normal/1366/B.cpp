#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, x, m;
int l[N], r[N];

int get(int l1, int r1, int l2, int r2)
{
	int L = max(l1, l2);
	int R = min(r1, r2);
	return L <= R;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x >> m;
		int curL = x, curR = x;
		for(int i = 1; i <= m; i++)
		{
			cin >> l[i] >> r[i];
			if(get(curL, curR, l[i], r[i]))
			{
				curL = min(curL, l[i]);
				curR = max(curR, r[i]);
			}
		}
		cout << curR - curL + 1 << endl;
	}
	return 0;
}