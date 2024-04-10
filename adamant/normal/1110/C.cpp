#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> ans;
    int cnt = 0;
    for(int ta = 4; ta <= (1LL << 25); ta *= 2) {
		int a = ta - 1;
		cnt++;
		if(__builtin_popcount(a + 1) == 1) {
			int as = 0;
			for(int b = 1; b < a; b++) {
				if((a ^ b) % b == 0) {
					as = b;
				}
			}
			ans[a] = as;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int a;
		cin >> a;
		int t = 1;
		while(t <= a) {
			t *= 2;
		}
		if(t - 1 == a) {
			cout << ans[a] << "\n";
		} else {
			cout << t - 1 << "\n";
		}
	}
    return 0;
}