#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

point cmul(point a, point b) {
    return conj(a) * b;
}
ftype dot(point a, point b) {
    return cmul(a, b).x();
}
ftype cross(point a, point b) {
    return cmul(a, b).y();
}

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;


signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	string ans;
	int t = (n - k) / 2;
	for(auto c: s) {
		if(c == '(') {
			ans += c;
		} else if(t) {
			t--;
			ans.pop_back();
		} else {
			ans += c;
		}
	}
	cout << ans << endl;
	return 0;
}