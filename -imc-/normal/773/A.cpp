#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

inline int iceil(int x, int y) {
	return x / y + (x % y > 0 ? 1 : 0);
}

void solve() {
	int x = nxt(), y = nxt(), p = nxt(), q = nxt();

	if (p == 0 && x != 0) {
		puts("-1");
		return;
	}
	if (p == 0 && x == 0) {
		puts("0");
		return;
	}
	if (p == q && x < y) {
		puts("-1");
		return;
	}
	if (p == q && x == y) {
		puts("0");
		return;
	}

	y -= x;
	q -= p;

	int k = max(iceil(x, p), iceil(y, q));
	cout << 1ll * (p + q) * k - x - y << "\n";
}

int main(){

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}