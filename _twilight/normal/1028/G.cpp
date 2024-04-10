#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

const int Kmx = 1e4;
const ll Vmx = 10004205361450474ll;

ll f[6][10004];

ll dp(int rest, ll L) {
	if (!rest) {
		return L;
	}
	if (L > Kmx) {
		return min(dp(rest, Kmx) + L - Kmx, Vmx);
	}
	int l = L;
	ll &rt = f[rest][l];
	if (rt) {
		return rt;
	}
	rt = l;
	for (int i = 0; i < l; i++) {
		rt = dp(rest - 1, rt) + 1;
	}
	rt = dp(rest - 1, rt);
	return rt = min(rt, Vmx);
}

int main() {
	ll l = 1, r = dp(5, 1);
	for (int rest =	4, idx; ~rest; rest--) {
		vector<ll> list;
		ll curL = l;
		for (int i = 1, _ = (int) min((ll) Kmx, l); i <= _; i++) {
			curL = dp(rest, curL);
			list.push_back(curL);
			curL++;
		}
		printf("%d", (signed) list.size());
		for (auto x : list) {
			printf(" "Auto, x);
		}
		putchar('\n');
		fflush(stdout);
		
		scanf("%d", &idx);
		if (idx < 0) {
			return 0;
		}
		if (idx > 0) {
			l = list[idx - 1] + 1;
		}
		if (idx < (signed) list.size()) {
			r = list[idx + 1];
		}
	}
	return 0;
}