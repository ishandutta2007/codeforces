#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long
const signed ll llf = (signed ll) (~0ull >> 2);

template <const int sz>
class Sieve {
	public:
		bitset<sz> vis;
		vector<int> pri;

		Sieve() {
			vis.reset();
			for (int i = 2; i < sz; i++) {
				if (!vis.test(i)) {
					pri.push_back(i);
				}
				for (int j = 0; j < (signed) pri.size() && i * pri[j] < sz; j++) {
					vis.set(i * pri[j]);
					if (!(i % pri[j])) {
						break;
					}
				}
			}
		}

		vector<ll> get_primary_factor(ll x) {
#ifdef local
			assert(sz * 1ll *sz > x);
#endif
			vector<ll> rt;
			for (int* p = pri.data(); *p * 1ll * *p <= x; p++) {
				if (!(x % *p)) {
					while (!(x % *p)) {
						x /= *p;
					}
					rt.push_back(*p);
				}
			}
			if (x > 1) {
				rt.push_back(x);
			}
			return rt;
		}
};

#ifdef local
Sieve<10000> euler;
#else
Sieve<35000000> euler;
#endif

typedef class Query {
	public:
		ll n, m;
		boolean* res;
		
		boolean operator < (Query b) const {
			return m < b.m;
		}
} Query;

typedef class Node {
	public:
		int p;
		ll d;

		Node() {	}
		Node(int p, ll d) : p(p), d(d) {	}
		
		boolean operator < (Node b) const {
			return d < b.d;
		}
} Node;

void exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int T;
Query *qs;
boolean *res;

inline void init() {
	scanf("%d", &T);
	qs = new Query[T + 1];
	res = new boolean[T + 1];
	for (int t = 0; t < T; t++) {	
		scanf(Auto""Auto, &qs[t].n, &qs[t].m);
		qs[t].res = res + t;
	}
}

ll f[100005];
inline void solve(Query*& q) {
	ll m = q->m;
	if (m == 1) {
		while (q != qs + T && q->m == m) {
			*(q->res) = false;
			q++;
		}
		return;
	}
	vector<ll> fac = move(euler.get_primary_factor(m)); 
	if ((signed) fac.size() == 1) {
		while (q != qs + T && q->m == m) {
			*(q->res) = !(q->n % m);
			q++;
		}
		return;
	}
	if ((signed) fac.size() == 2) {
		ll a = fac[0], b = fac[1], x, y;
		exgcd(b % a, a, x, y);
		(x < 0) ? (x += a) : (0);
		while (q != qs + T && q->m == m) {
			*(q->res) = (q->n % a * x % a * b <= q->n);
			q++;
		}
		return;
	}
	
	priority_queue<Node> que;
	for (int i = 0; i < fac[0]; i++) {
		f[i] = llf;
	}
	que.push(Node(0, f[0] = 0));
	while (!que.empty()) {
		Node e = que.top();
		que.pop();
		if (e.d != f[e.p]) {
			continue;
		}
		for (int i = 1, eu; i < (signed) fac.size(); i++) {
			eu = (e.p + fac[i]) % fac[0];
			if (f[e.p] + fac[i] < f[eu]) {
				que.push(Node(eu, f[eu] = f[e.p] + fac[i]));
			}
		}
	}

	while (q != qs + T && q->m == m) {
		*(q->res) = (f[q->n % fac[0]] <= q->n);
		q++;
	}
}

int main() {
	init();
	Query *pq = qs, *ped = qs + T;
	sort(pq, ped);
	while (pq != ped) {
		solve(pq);
	}
	for (int i = 0; i < T; i++) {
		puts((res[i]) ? ("YES") : ("NO"));
	}
	return 0;
}