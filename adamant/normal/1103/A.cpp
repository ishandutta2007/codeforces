#include <bits/extc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
const int maxn = 1e5 + 42;

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cntx = 0, cnty = 0;
    for(auto c: s) {
		if(c == '0') {
			cout << 1 << ' ' << cntx + 1 << endl;
			cntx++;
			cntx %= 4;
		} else {
			cout << 3 << ' ' << 2 * cnty + 1 << endl;
			cnty++;
			cnty %= 2;
			
		}
	}
    return 0;
}