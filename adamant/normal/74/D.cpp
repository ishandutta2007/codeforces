#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	ordered_set endp;
	endp.insert(0);
	endp.insert(n + 1);
	set<pair<int, int>, greater<pair<int, int>>> segs = {{n, 1}};
	map<int, int> place;
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 0)
		{
			int l, r;
			cin >> l >> r;
			cout << endp.order_of_key(r + 1) - endp.order_of_key(l) << "\n";
		}
		else
		{
			if(place[t])
			{
				auto it = endp.find(place[t]);
				auto L = prev(it), R = next(it);
				segs.erase({*it - *L - 1, *L + 1});
				segs.erase({*R - *it - 1, *it + 1});
				segs.insert({*R - *L - 1, *L + 1});
				endp.erase(it);
				place[t] = 0;
			}
			else
			{
				auto it = *segs.begin();
				int L = it.second, R = L + it.first;
				int M = L + it.first / 2;
				segs.erase(it);
				segs.insert({M - L, L});
				segs.insert({R - M - 1, M + 1});
				endp.insert(M);
				place[t] = M;
			}
		}
	}
}