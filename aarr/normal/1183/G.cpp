#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 200 * 1000 + 5;
pair <int, int> a[N];
pair <int, int> b[N];
pair <int, int> c[N];
vector <int> v;
vector <int> u;
multiset <int> s;
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		while(s.size()) {
			s.erase(s.begin());
		}
		v.clear();
		int n;
		cin >> n;
		for (int j = 0; j <= n; j++) {
			b[j] = {0, 0};
		}
		for (int j = 0; j < n; j++) {
			cin >> a[j].first;
			cin >> a[j].second;
			b[a[j].first].first++;
			if (a[j].second == 1)
				b[a[j].first].second++;
		}
		sort(b + 1, b + n + 1);
		int x = N, ans = 0;
		v.push_back(0);
		v.push_back(N);
		//cout << endl;
		for (int j = n; j > 0; j--) {
			//cout << b[j].first << " " << b[j].second << endl;
			if(b[j].first < x) {
				x = b[j].first;
				ans += x;
				if (x > 0)
					v.push_back(x);
			}
			else {
				if (x > 1) {
					x--;
					ans += x;
					v.push_back(x);
				}
			}
			//cout << x << endl;
		}
		cout << ans << " ";
		int ans2 = 0;
		sort(v.begin(), v.end());
		//for (int j = 1; j <= n; j++) {
		//	int z = lower_bound(v.begin(), v.end(), b[j].first) - v.begin() - 1;
		//	c[j].first = v[z];
		//	c[j].second = b[j].second;
		//}
		//sort(c + 1, c + n + 1);
		int y = n;
		for (int j = (int) v.size() - 2; j > 0; j--) {
			while (b[y].first >= v[j]) {
				s.insert(b[y].second);
				//u.push_back(b[y].second);
				y--;
			}
			set <int> :: iterator it = s.end();
			it--;
			//sort(u.begin(), u.end());
			ans2 += min(v[j], *it);
			//u.pop_back();
			s.erase(it);
		}
		cout << ans2 << endl;
	}
	return 0;
}