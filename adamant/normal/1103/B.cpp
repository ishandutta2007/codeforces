#include <bits/extc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
const int maxn = 1e5 + 42;

int m;

int get(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	char c;
	cin >> c;
	return c == 'x' ? x : y;
}

int play() {
	string type;
	cin >> type;
	if(type == "start") {
		for(int i = 0; i <= 30; i++) {
			int A = 1LL << i;
			int B = 1LL << (i + 1);
			int res = get(A, B);
			if(i == 0 && res == 1) {
				return get(0, 1);
			}
			if(res == A) {
				int ans = A;
				for(int j = i - 1; j >= 0; j--) {
					int A = 1LL << j;
					int B = 1LL << (j + 1);
					int res = get(ans + A, ans + B);
					if(res == ans + A) {
						ans += A;
					}
				}
				return ans;
			}
		}
	} else {
		return -1;
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
		int ans = play();
		if(ans == -1) {
			break;
		} else {
			cout << "! " << 1 + ans << endl;
		}
	}
    return 0;
}