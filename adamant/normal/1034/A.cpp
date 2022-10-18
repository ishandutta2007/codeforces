#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define all(x) begin(x), end(x)

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

const ftype pi = acos(-1);

point cmul(point a, point b) {
    return conj(a) * b;
}
ftype dot(point a, point b) {
    return cmul(a, b).x();
}
ftype cross(point a, point b) {
    return cmul(a, b).y();
}

const int maxn = 1.5e7 + 42;
int pr[maxn];
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 2; i < maxn; i++) {
		if(!pr[i]) {
			for(int j = i; j < maxn; j += i) {
				if(!pr[j]) {
					pr[j] = i;
				}
			}
		}
	}
	int n;
	cin >> n;
	int a[n];
	int g = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	
	for(int i = 0; i < n; i++) {
		a[i] /= g;
		while(a[i] != 1) {
			if(pr[a[i]] != pr[a[i] / pr[a[i]]]) {
				cnt[pr[a[i]]]++;
			}
			a[i] /= pr[a[i]];
		}
	}
	int sm = *max_element(cnt, cnt + maxn);
	if(sm == 0) {
		cout << -1 << endl;
	} else {
		cout << n - sm << endl;
	}
	return 0;
}