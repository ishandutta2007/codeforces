#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

signed main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int c[n];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);
	int l = 0, r = 1e9 + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		int cnt1 = 0;
		int cnt2 = 0;
		for(int i = 0; i < n; i++)
			if(c[i] < m)
				cnt1 += m - c[i];
			else
				cnt2 += c[i] - m;
		if(cnt2 >= cnt1 && cnt1 <= k)
			l = m;
		else
			r = m;
	}
	int L = l;
	l = 0, r = 1e9 + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		int cnt1 = 0;
		int cnt2 = 0;
		for(int i = 0; i < n; i++)
			if(c[i] < m)
				cnt1 += m - c[i];
			else
				cnt2 += c[i] - m;
		if(cnt1 >= cnt2 && cnt2 <= k)
			r = m;
		else
			l = m;
	}
	int R = r;
	cout << R - L << "\n";
}