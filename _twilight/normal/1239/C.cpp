#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
void discrete(T* a, int* b, int n) {
	vector<T> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 1e5 + 5;

typedef class Event {
	public:
		int op;
		ll t;
		int p;
		
		Event(int op, ll t, int p) : op(op), t(t), p(p) {	}

		boolean operator < (Event b) const {
			if (t ^ b.t)
				return t > b.t;
			if (op ^ b.op)
				return op > b.op;
			return p > b.p;
		}
} Event;

int n, P;
queue<int> Q;
set<int> Sq, Sw;
vector<ll> ans;
priority_queue<Event> Qe;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> P;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		Qe.push(Event(0, x, i));
	}
	ans.resize(n + 1);
	while (!Qe.empty()) {
		Event e = Qe.top();
		Qe.pop();
		if (e.op == 0) {
			int p = e.p;
			if (Sq.empty()) {
				Q.push(p);
				Sq.insert(p);
				Qe.push(Event(1, e.t + P, p));
			} else if (*Sq.begin() > e.p) {
				Q.push(p);
				Sq.insert(p);
			} else {
				Sw.insert(e.p);
			}
		} else {
			ans[e.p] = e.t;
			Q.pop();
			Sq.erase(Sq.find(e.p));
			if (!Sw.empty() && (Sq.empty() || *Sw.begin() < *Sq.begin())) {
				Q.push(*Sw.begin());
				Sq.insert(*Sw.begin());
				Sw.erase(Sw.begin());
			}
			if (!Q.empty()) {
				int p = Q.front();
				Qe.push(Event(1, e.t + P, p));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}