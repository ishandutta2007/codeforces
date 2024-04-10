#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1005;
 
struct data
{
	int sz, money;
	int idx;
};
 
int n, k;
data a[N]; //{sz, price}
pair<int, int> r[N];
int cache[N][N];
vector<pair<int, int> > v;
 
bool comp(data &d1, data &d2)
{
	return d1.sz > d2.sz;
}
 
int dp(int i, int j)
{
	if(i > n)
		return 0;
	if(j > k)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	ans = dp(i + 1, j);
	if(a[i].sz <= r[j].first)
		ans = max(ans, a[i].money + dp(i + 1, j + 1));
	return ans;
}
 
void path(int i, int j)
{
	if(i > n)
		return;
	if(j > k)
		return;
	int &ans = cache[i][j];
	if(ans == dp(i + 1, j))
		return path(i + 1, j);
	else
	{
		v.push_back({a[i].idx, r[j].second});
		return path(i + 1, j + 1);
	}
}
 
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].sz >> a[i].money;
		a[i].idx = i;
	}
	sort(a + 1, a + n + 1, comp);
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> r[i].first;
		r[i].second = i;
	}
	sort(r + 1, r + k + 1);
	reverse(r + 1, r + k + 1);
	int ans = dp(1, 1);
	path(1, 1);
	cout << v.size() << " " << ans << endl;
	for(auto &it:v)
		cout << it.first << " " << it.second << endl;
	return 0;
}