#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 105;

int n;
int a[N], b[N];
map<vector<int>, int> m;
int lim = (1 << 15);

void workLeft()
{	
	for(int i = 1; i <= n; i++)
		b[i] = a[i] >> 15;
	for(int x = 0; x < lim; x++)
	{
		vector<int> cur;
		for(int i = 1; i <= n; i++)
			cur.push_back(__builtin_popcount(b[i] ^ x));
		for(int i = 1; i < n; i++)
			cur[i] -= cur[0];
		cur[0] = 0;
		m[cur] = x;
	}
}

void workRight()
{	
	for(int i = 1; i <= n; i++)
		b[i] = a[i] % (1 << 15);
	for(int x = 0; x < lim; x++)
	{
		vector<int> cur;
		for(int i = 1; i <= n; i++)
			cur.push_back(__builtin_popcount(b[i] ^ x));
		for(int i = 1; i < n; i++)
			cur[i] -= cur[0];
		cur[0] = 0;
		for(int i = 1; i < n; i++)
			cur[i] *= -1;
		if(m.find(cur) != m.end())
		{
			int ans = m[cur] * (1 << 15) + x;
			cout << ans;
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	workLeft();
	workRight();
	cout << -1;
	return 0;
}