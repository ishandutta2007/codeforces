#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>
const signed int inf = (signed) (~0u >> 1);
const signed ll llf = (signed ll) (~0ull >> 2);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

ll gcd(ll a, ll b) {
	return (b) ? (gcd(b, a % b)) : (a);
}

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:
		
		Input():file(NULL)	{	};
		Input(FILE* file):file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return buf[ss++];
		}
}Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input in (stdin);

const int S = 2048;

int n;
ll *a;
int *c;
ll K, G;
ll v[13];
int cnt[S];
ll f[13][S];
vector<ll> P;
vector<pil> b;
vector<int> st;

inline void init() {
	in >> n >> K;
	a = new ll[(n + 1)];
	c = new int[(n + 1)];
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		G = gcd(a[i], G);
	}
	for (int i = 1; i <= n; i++) {
		in >> c[i];
	}
	if (G == 1) {
		puts("0");
		exit(0);
	}
}

inline void solve() {
	for (ll x = 2; x * x <= G; x++) {
		if (!(G % x)) {
			P.push_back(x);
			while (!(G % x))
				G /= x;
		}
	}
	if (G > 1)
		P.push_back(G);

	for (int i = 1; i <= n; i++) {
		ll v = 1;
		for (auto& p : P) {
			while (!(a[i] % p))
				a[i] /= p, v *= p;
		}
		a[i] = v;
	}
	
	int sz = P.size();
	pli tmp[n + 1];
	for (int i = 1; i <= n; i++)
		tmp[i] = pli(a[i], c[i]);
	sort(tmp + 1, tmp + n + 1);
	
	for (int i = 1, _i = 1, ed; i <= n; i = _i) {
		while (_i <= n && tmp[i].first == tmp[_i].first)
			_i++;
		ed = min(i + sz, _i);
		for (int _ = i; _ < ed; _++) {
			b.push_back(pil(tmp[_].second, tmp[_].first));
		}
	}
	sort(b.begin(), b.end());
	
	f[0][0] = 0;
	int all = (1 << sz) - 1;
	pfill(f[0] + 1, f[12], llf);
	for (int i = 0, val; i < (signed) b.size(); i++) {
		val = b[i].first;
		pfill(v, v + sz, 1ll);
		ll x = b[i].second;
		for (int j = 0; j < sz; j++) {
			while (!(x % P[j])) {
				v[j] *= P[j];
				x /= P[j];
			}
		}
	
		st.clear();
		for (int s = 1; s <= all; s++) {
			if (cnt[s] >= sz)
				continue;
			ll prod = 1;
			for (int j = 0; j < sz && prod <= K; j++)
				if (s & (1 << j))
					prod *= v[j];
			if (prod > K)
				continue;
			st.push_back(s);
			cnt[s]++;
		}

		if (!st.empty()) {
			for (int c = sz - 1; ~c; c--) {
				for (auto& t : st) {
					for (int s = t; s <= all; s = (s + 1) | t) {
						if (f[c][t ^ s] != llf) {
							f[c + 1][s] = min(f[c + 1][s], f[c][t ^ s] + val);
						}
					}
				}
			}
		}
	}

	ll ans = llf;
	for (int i = 1; i <= sz; i++) {
		if (f[i][all] != llf) {
			ans = min(ans, i * f[i][all]);
		}
	}
	if (ans == llf)
		puts("-1");
	else
		printf(Auto, ans);
}

int main() {
	init();
	solve();
	return 0;
}