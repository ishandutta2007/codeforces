#include <bits/stdc++.h>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

int n, m;
ll ans = 0;
int *a, *b, *c;
priority_queue<ll, vector<int>, greater<int> > Q;

inline void init() {
	scanf("%d", &n);
	a = new int[(n + 1)];
	b = new int[(n + 1)];
	c = new int[(n + 1)];
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		ans += a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	b[m = 1] = a[1], c[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			c[m]++;
		} else {
			b[++m] = a[i], c[m] = 1;
		}
	}
}

vector<ll> tmp;
inline void solve() {
	int s = c[1];
	for (int i = 2; i <= m; i++) {
		int r = min(s, (s + c[i]) >> 1);
		int _c = min(r, c[i]), dif = 0;
		int _s = s + c[i];
		int intersect = (signed) Q.size() - (r - _c);
//		cerr << s << " " << s + c[i] << " " << r << " " << intersect << '\n';
		if (intersect <= 0) {
			while (_c--) {
				Q.push(b[i]);
//				cerr << ">" << b[i] << '\n';
			}
		} else {
			for (int j = 0; j < intersect; j++) {
				ll x = Q.top();
//				cerr << ">" << x << '\n';
				Q.pop();
				if (x > b[i]) { 
					tmp.push_back(x);
					tmp.push_back((b[i] << 1) - x);
					dif++;
				}
			}
			if ((_s & 1) && (s > (_s >> 1)) && !tmp.empty())
				tmp.pop_back();
			while (!tmp.empty()) {
//				cerr << "<" << tmp.back() << '\n';
				Q.push(max(tmp.back(), 0ll));
				tmp.pop_back();
			}
			while ((signed) Q.size() < r) {
				Q.push(b[i]);
//				cerr << '<' << b[i] << '\n';
			}
			while ((signed) Q.size() > r) {
//				cerr << '>' << Q.top() << '\n';
				Q.pop();
			}
		}
		s += c[i];
	}
	while (!Q.empty()) {
		ans -= Q.top();
		Q.pop();
	}
	printf(Auto, ans);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("a.out", "w", stdout);
	init();
	solve();
	return 0;
}