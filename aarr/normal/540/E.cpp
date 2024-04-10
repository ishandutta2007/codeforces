#include <iostream>
#include <map>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

map <int, int> mp;
map <int, int> cnt;
ordered_set os;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (!mp[x]) {
			mp[x] = x;
		}
		if (!mp[y]) {
			mp[y] = y;
		}
		swap(mp[x], mp[y]);
	}
	int c = 0;
	for (auto p : mp) {
		int x = p.first, y = p.second;
		cnt[x] = c;
		c++;
	}
	long long ans = 0;
	for (auto p : mp) {
		int x = p.first, y = p.second;
		int s = abs(x - y - cnt[x] + cnt[y]);
		ans += s;
	//	cout << "73 " << x << " " << y << " " << s << endl;
		ans += os.size() - os.order_of_key(y);
		os.insert(y);
	}
	cout << ans;
	return 0;
}