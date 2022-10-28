#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n, d;

bool pos(int n, int d, int curLevel)
{
	int mx = 1, depth = curLevel;
	int minD = 0;
	//curlevel... curLevel + n - 1
	int maxD = (curLevel + n - 1) * (curLevel + n) / 2 - (curLevel - 1) * (curLevel) / 2;
	int curN = n;
	while(curN > 0)
	{
		int take = min(curN, mx);
		minD += take * depth;
		curN -= take;
		mx *= 2;
		depth++;
	}
	if(d < minD || d > maxD)
		return 0;
	return 1;
}

int par[N];
int val = 0;

int work(int n, int d, int curLevel)
{
	++val;
	n--;
	d -= curLevel;
	if(n == 0 && d == 0)
		return val;
	int cur = val;
	for(int left = n; left >= 1; left--)
	{
		for(int takeD = 1; takeD <= d; takeD++)
		{
			if(pos(left, takeD, curLevel + 1))
			{
				if(d - takeD > 0 && n - left > 0 && pos(n - left, d - takeD, curLevel + 1))
				{
					par[work(left, takeD, curLevel + 1)] = cur;
					par[work(n - left, d - takeD, curLevel + 1)] = cur;
					return cur;
				}
				else if(d == takeD && n == left)
				{
					par[work(left, takeD, curLevel + 1)] = cur;
					return cur;
				}
			} 
		}
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		val = 0;
		cin >> n >> d;
		if(!pos(n, d, 0))
		{
			cout << "NO" << endl;
			continue;
		}
		if(work(n, d, 0))
		{
			cout << "YES" << endl;
			for(int i = 2; i <= n; i++)
				cout << par[i] << " ";
			cout << endl;
		}
	}
	return 0;
}