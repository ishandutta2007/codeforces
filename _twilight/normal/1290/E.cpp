#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define pii pair<int, int>

const int N = 150005;

typedef class Event {
	public:
		int op, p, v;

		Event(int op, int p, int v) : op(op), p(p), v(v) {	}

		boolean operator < (Event b) const {
			return p > b.p;
		}
} Event;

typedef class Fenwick {
	public:
		int n;
		vector<int> a;

		void init(int n) {
			this->n = n;
			a = vector<int>(n + 1, 0);
		}
		void add(int idx, int v) {
			for ( ; idx <= n; idx += (idx & (-idx)))
				a[idx] += v;
		}
		int query(int idx) {
			int rt = 0;
			for ( ; idx; idx -= (idx & (-idx)))
				rt += a[idx];
			return rt;
		}
		int query(int l, int r) {
			return query(r) - query(l - 1);
		}
} Fenwick;

int n;
int a[N];
ll ans[N];

void add(int l, int r, ll d) {
	ans[l] += d;
	ans[r + 1] -= d;
//	cerr << l << " " << r << " " << '\n';
}

void dividing(int l, int r) {
	if (l == r) {
		ans[a[l]] += 1;
		return;
	}
	int mid = (l + r) >> 1;
	
	vector<int> stk;
	vector<int> tg;
	vector<Event> E;
	Fenwick fen;
	for (int i = r; i > mid; i--)
		E.emplace_back(0, a[i], i);
	int len = r - mid;
	set<int> S;
	S.insert(n + 1);
	for (int i = mid; i >= l; i--) {
		E.emplace_back(1, a[i], *S.upper_bound(a[i]));
		S.insert(a[i]);
	}
	sort(E.begin(), E.end());
	fen.init(len);
	for (int i = 1; i <= len; i++)
		fen.add(i, 1);
	for (auto it = E.begin(); it != E.end(); it++) {
		if ((*it).op == 0) {
			int p = (*it).v, q;
			int sum = 0;
			while (!stk.empty() && stk.back() > p) {
				q = stk.back();
				sum += tg.back();
				stk.pop_back(), tg.pop_back();
				add(a[q], (stk.empty()) ? (n) : (a[stk.back()] - 1), 1ll * fen.query(q - mid - 1) * sum);
			}
			if (!tg.empty())
				tg.back() += sum;
			stk.push_back(p);
			tg.push_back(0);
			fen.add(p - mid, -1);
		} else if ((*it).op == 1){
			int ql = (*it).p, qr = (*it).v - 1;
			int L = 0, R = (signed) stk.size() - 1, Mid;
			while (L <= R) {
				Mid = (L + R) >> 1;
				if (a[stk[Mid]] > qr) {
					L = Mid + 1;
				} else {
					R = Mid - 1;
				}
			}
			if (L == (signed) stk.size()) {
				add(ql, qr, fen.query(len));
			} else {
				add(ql, a[stk.back()] - 1, fen.query(len));
				add(a[stk[L]], qr, fen.query(stk[L] - mid - 1));
				tg.back() += 1;
				tg[L] -= 1;
			}
		}
//		cerr << (*it).p << " " << Vmsg(tg) << " " << Vmsg(stk) << '\n';
 	}

	len = mid - l + 1;
	stk.clear(), tg.clear(), E.clear();
	for (int i = l; i <= mid; i++)
		E.emplace_back(0, a[i], i);
	S.clear();
	S.insert(n + 1);
	for (int i = mid + 1; i <= r; i++) {
		E.emplace_back(1, a[i], *S.upper_bound(a[i]));
		S.insert(a[i]);
	}
	sort(E.begin(), E.end());
	fen.init(len);
	for (int i = 1; i <= len; i++)
		fen.add(i, 1);
	for (auto it = E.begin(); it != E.end(); it++) {
		if ((*it).op == 0) {
			int p = (*it).v, q;
			int sum = 0;
			while (!stk.empty() && stk.back() < p) {
				q = stk.back();
				sum += tg.back();
				stk.pop_back(), tg.pop_back();
				add(a[q], (stk.empty()) ? (n) : (a[stk.back()] - 1), 1ll * fen.query(mid - q) * sum);
			}
			if (!tg.empty())
				tg.back() += sum;
			stk.push_back(p);
			tg.push_back(0);
			fen.add(mid - p + 1, -1);
		} else if ((*it).op == 1){
			int ql = (*it).p, qr = (*it).v - 1;
			int L = 0, R = (signed) stk.size() - 1, Mid;
			while (L <= R) {
				Mid = (L + R) >> 1;
				if (a[stk[Mid]] > qr) {
					L = Mid + 1;
				} else {
					R = Mid - 1;
				}
			}
			if (L == (signed) stk.size()) {
				add(ql, qr, fen.query(len));
			} else {
				add(ql, a[stk.back()] - 1, fen.query(len));
				add(a[stk[L]], qr, fen.query(mid - stk[L]));
				tg.back() += 1; 
				tg[L] -= 1;
			}
		}
 	}

	dividing(l, mid);
	dividing(mid + 1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	dividing(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i] += ans[i - 1]);
	}
	return 0;
}