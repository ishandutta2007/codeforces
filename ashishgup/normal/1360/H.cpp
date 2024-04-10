#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, reqd;
int a[N];
string s[N];

bool check(int x)
{
	int rem = (1LL << m) - n;
	int smaller = 0;
	if(rem % 2)
		smaller = rem / 2;
	else
		smaller = rem / 2 - 1;
	int have = x;
	for(int i = 1; i <= n; i++)
		have -= (a[i] < x);
	return have >= smaller;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		set<int> have;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			int val = 0;
			for(auto &it:s[i])
				val = val * 2 + (it - '0');
			a[i] = val;
			have.insert(a[i]);
		}
		sort(a + 1, a + n + 1);
		int ans = binsearch(0, (1LL << m) - 1);
		while(have.find(ans) != have.end())
			ans++;
		for(int i = m - 1; i >= 0; i--)
			cout << (ans >> i & 1);
		cout << endl;
	}
	return 0;
}