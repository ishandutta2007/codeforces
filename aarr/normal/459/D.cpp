#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair <int, int>, null_type, less<pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update>

const int N = 1000 * 1000 + 5;
int n;

vector <int> v[4 * N];
int a[N];
int fl[N];
int fr[N];
map <int, vector <int> > mp;
ordered_set s;
void build(int id = 1, int L = 0, int R = n) {
	for (int i = L; i < R; i++) {
		v[id].push_back(a[i]);
	}
	if (R - L == 1) {
		return ;
	}
	int md = (L + R) / 2;
	build(id * 2, L, md);
	build(id * 2 + 1, md, R);
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].push_back(i);
		fl[i] = mp[a[i]].size();
//		s.insert({fl[i], -i})	
	}
	for (int i = n - 1; i >= 0; i--) {
		fr[i] = mp[a[i]].size() - fl[i] + 1;
	//	cout << i << " " << fl[i] << " " << fr[i] << endl;
	//	cout << i << " " << s.order_of_key({fl[i], -1}) << endl;
		ans += s.order_of_key({fl[i], -1});
		s.insert({fr[i], i});
	}
	cout << ans << endl;
	return 0;
}