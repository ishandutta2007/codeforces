#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define int int64_t
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

const ftype inf = 1e16;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int scr[1 << 12][1 << 12];
int sub[1 << 12];
int cnt[1 << 12];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int w[n];
    for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	reverse(w, w + n);
    for(int i = 0; i < m; i++) {
		bitset<12> gg;
		cin >> gg;
		cnt[gg.to_ulong()]++;
	}
	int maxs = 1 << n;
	for(int i = 0; i < maxs; i++) {
		for(int j = 0; j < n; j++) {
			if(((i >> j) & 1) == 0) {
				sub[i] += w[j];
			}
		}
	}
	int ans[q], kk[q];
	memset(ans, 0, sizeof(ans));
	vector<int> queries[maxs];
	for(int i = 0; i < q; i++) {
		bitset<12> gg;
		cin >> gg >> kk[i];
		queries[gg.to_ulong()].push_back(i);
	}
	for(int i = 0; i < maxs; i++) {
		int total[101];
		memset(total, 0, sizeof(total));
		for(int j = 0; j < maxs; j++) {
			scr[i][j] = sub[i ^ j];
			if(scr[i][j] <= 100) {
				total[scr[i][j]] += cnt[j];
			}
		}
		for(auto it: queries[i]) {
				for(int x = 0; x <= kk[it]; x++) {
					ans[it] += total[x];
				}
		}
	}
	for(int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
    return 0;
}