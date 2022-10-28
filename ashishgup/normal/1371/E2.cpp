#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, p;
int a[N], f[N];
bool mark[N];

int32_t main()
{
	IOS;
	cin >> n >> p;
	map<int, int> freq;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	int mn = max(1LL, a[n] - n);
	int mx = a[n];
	int sz = mx - mn + 1;
	if(sz == 0)
	{
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] <= mn)
			cnt++;
	int idx = 0;
	f[++idx] = cnt;
	for(int i = 2; i <= sz; i++)
		f[++idx] = f[i - 1] + freq[mn + i - 1];
	int gap = f[sz] - (p - 1);
	vector<int> ans;
	for(int i = sz; i >= 1; i--)
	{
		int rem = f[i] % p;
		if(i - rem >= 1)
			mark[i - rem] = 1;
		if(mark[i] && i - p >= 1)
			mark[i - p] = 1;
		if(!mark[i] && sz - i >= gap)
			ans.push_back(mn + i - 1);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto &it:ans)
		cout << it << " ";
	cout << endl;
	return 0;
}