//Be Name Khoda
//no comment...
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)107;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
string s[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector<pair<int, pair<int, int> > >emp;
	for (int i = 0; i < n; i++)
		for (int len = 0; len < s[i].size(); len++)
		if(s[i][len] == '.')
		{
			int t = 0;
			if(len != 0 && s[i][len - 1] == 'S')
				t++;
			if(len != s[i].size() - 1 && s[i][len + 1] == 'S')
				t++;
			
			emp.push_back({t, {i, len}});
		}
	
	sort(emp.begin(), emp.end());
	for (int i = 0; i < k; i++)
		s[emp[i].second.first][emp[i].second.second] = 'x';
	
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int len = 0; len < s[i].size(); len++)
			if(s[i][len] == 'S')
			{
				if(len != 0 && s[i][len - 1] != '.' && s[i][len - 1] != '-')
					ans++;
				if(len != s[i].size() - 1 && s[i][len + 1] != '.' && s[i][len + 1] != '-')
					ans++;
				
			}
	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
}