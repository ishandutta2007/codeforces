
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1005;
 
int n, k;
int c[N], t[N];
vector<pair<int, int> > s, p;
double ans = 0;
bool vis[N];
 
int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i] >> t[i];
		if(t[i] == 1)
			s.push_back({c[i], i});
		else
		{
			p.push_back({c[i], i});
			ans += c[i];
		}
	}
	sort(s.rbegin(), s.rend());
	vector<int> v;
	int printed = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(i <= k - 2)
		{
			ans += 0.5 * s[i].first;
			vis[s[i].second] = 1;
		}
		else
			ans += s[i].first;
	}
	double mn = 1e9;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			mn = min(mn, 1.0 * c[i]);
	}
	if(s.size() >= k)
		ans -= 0.5 * mn;
	cout << fixed << setprecision(1) << ans << endl;
	for(int i = 0; i < s.size(); i++)
	{
		if(i <= k - 2)
		{
			printed++;
			cout << 1 << " " << s[i].second << endl;
		}
	}
	vector<int> rem;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			rem.push_back(i);
	}
	while(printed + 1 < k)
	{
		cout << 1 << " " << rem.back() << endl;
		rem.pop_back();
		printed++;
	}
	cout << rem.size() << " ";
	for(auto &it:rem)
		cout << it << " ";
	return 0;
}