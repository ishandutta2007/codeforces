#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? 1LL * x * bpow(x, n - 1) % mod : bpow(1LL * x * x % mod, n / 2) : 1;
}



bool print(int l, int r) {
	cout << l << ' ' << r << endl;
	string ans;
	cin >> ans;
	if(l == r && ans == "Yes") {
		exit(0);
	}
	return ans == "Yes";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int n, k;
	cin >> n >> k;
	k++;
	int l = 1, r = n + 1;
	while(true) {
		int m = (l + r) / 2;
		if(r - l <= 5 * k) {
		    int tr = l + rand() % (r - l);
			print(tr, tr);
			l = max<int>(1, l - k);
			r = min(n + 1, r + k);
		}
		m = (l + r) / 2;
		if(print(l, m)) {
			r = min(n + 1, m + k + 1);
			l = max<int>(1, l - k);
		} else {
			r = min(n + 1, r + k);
			l = max<int>(1, m - k);
		}
	}
	return 0;
}