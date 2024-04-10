#include <iostream> 
#include <vector>
#include <array>
 
using namespace std;
#define int long long
const int maxl = 22;

signed main() {
		if (1) {
		    ios_base::sync_with_stdio(false);
		    cin.tie(nullptr);
		    cout.tie(nullptr);
		}
	   int l, r;
	   cin >> l >> r;
	   vector <array<int, 3>> ans;
	   for (int i = 2; i <= maxl; ++i) {
	   	int cur = 1;
	   	ans.push_back({1, i, 1});
	   	for (int j = 2; j < i; ++j) {
	   		ans.push_back({j, i, cur});
	   		cur += (1 << (j - 2));
	   	}
	   }
	   int x = r - l + 1;
	   if (l == 1) {
	   	ans.push_back({1, maxl + 1, 1});
	   	--x;
	   	++l;
	   }
	   while (x > 0) {
	   	int b = 0;
	   	for (int i = 1; i < maxl; ++i) {
	   		if ((x >> i) & 1) b = i;
	   	}
	   	ans.push_back({b + 2, maxl + 1, l - 1});
	   	l += (1 << b);
	   	x -= (1 << b);
	   }
	   cout << "YES\n" << maxl + 1 << " " << (int)ans.size() << "\n";
	   for (auto i : ans) {
	   	cout << i[0] << " " << i[1] << " " << i[2] << "\n";
	   }
}