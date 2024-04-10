#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
tuple<int, int, int>,
null_type,
less<tuple<int, int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


int main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	ordered_set me[2];
	for(int i = 0; i < n; i++)
	{
		int a, t, x;
		scanf("%d%d%d", &a, &t, &x);
		if(a == 1)
			me[0].insert(make_tuple(x, t, i));
		else if(a == 2)
			me[1].insert(make_tuple(x, t, i));
		else
			cout << me[0].order_of_key(make_tuple(x, t + 1, 0)) - me[0].order_of_key(make_tuple(x, 0, 0)) -
					(me[1].order_of_key(make_tuple(x, t + 1, 0)) - me[1].order_of_key(make_tuple(x, 0, 0)))<< "\n";
	}
	return 0;
}
/*
1 2 3 4 5 6
6 1 2 3 4 5
1 6 3 2 5 4
6 3 2 5 4 1

*/