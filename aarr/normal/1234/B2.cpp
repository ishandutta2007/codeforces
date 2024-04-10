#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int N = 200 * 1000 + 5;
map <int, int> mp;
int ans[N];
vector <int> v;
int main() {
	int n, k, y = 0;
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (mp[x] == 0)
			v.push_back(x);
		if (mp[x] == 0 || y - mp[x] >= k) {
			y++;
			mp[x] = y;
		//	cout << x << " " << mp[x] << endl;
		}
	}
	int z = 0;
	for (int i = 0; i < v.size(); i++) {
		if (y - mp[v[i]] < k) {
		//	cout << v[i] << " " << mp[v[i]] << endl;
			ans[y - mp[v[i]]] = v[i];
			z++;
		}
	}
	cout << z << endl;
	for (int i = 0; i < z; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}