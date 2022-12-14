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
const int MAXN = (int)3e5 + 3;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
int part[MAXN], part2[MAXN];
ll sum(ll l, ll r)
{
	ll ans = part[r];
	if(l != 0)	
		ans -= part[l - 1];
	return ans;
}
ll sum2(ll l, ll r)
{
	ll ans = part2[r];
	if(l != 0)
		ans -= part2[l - 1];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t;
	int q;
	cin >> q;
	for (int i = 0; i < s.size(); i++)
		if(s[i] == 'C')
			s[i] = 'B';
	
	for (int i = 0; i < t.size(); i++)
		if(t[i] == 'C')
			t[i] = 'B';
	
	for (int i = 0; i < s.size(); i++)
	{
		part[i] = (s[i] - 'A');
		if(i != 0)
			part[i] += part[i - 1];
	}
	
	for (int i = 0; i < t.size(); i++)
	{
		part2[i] = (t[i] - 'A');
		if(i != 0)
			part2[i] += part2[i - 1];
	}
	for (int i = 0; i < q; i++)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		l1--, r1--, l2--, r2--;
		if(sum(l1, r1) > sum2(l2, r2))
			cout << 0;
		else
		if(sum(l1, r1) % 2 != sum2(l2, r2) % 2)
			cout << 0;
		else
		{
			
			
			
			int lp = l1 - 1, rp = r1;
				while(rp - lp > 1)
				{
					int mid = (lp + rp) >> 1;
					if(sum(mid, r1) > 0)
						lp = mid;
					else
						rp = mid;
				}
				int last1 = 0;
				if(s[r1] == 'B')
					last1 = 0;
				else
					last1 = r1 - rp + 1;
				
				
				lp = l2 - 1, rp = r2;
				while(rp - lp > 1)
				{
					int mid = (lp + rp) >> 1;
					if(sum2(mid, r2) > 0)
						lp = mid;
					else
						rp = mid;
				}
				int last2 = 0;
				if(t[r2] == 'B')
					last2 = 0;
				else
					last2 = r2 - rp + 1;
					
					
					
					
			if(sum(l1, r1) == 0 && sum2(l2, r2) > 0)
			{
				if(last1 > last2)
					cout << 1;
				else
					cout << 0;
			}
			else		
			if(sum(l1, r1) < sum2(l2, r2))
			{
				if(last1 >= last2)
					cout << 1;
				else
					cout << 0;
			}
			else
			{
				if(last2 % 3 == last1 % 3 && last1 >= last2)
					cout << 1;
				else
					cout << 0;
			}
		}
	}
}