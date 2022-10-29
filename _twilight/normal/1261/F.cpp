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

const int Mod = 998244353;
const int bzmax = 60;

int sum2(ll n) {
	n %= Mod;
	return ((n * (n + 1)) >> 1) % Mod;
}
int sum2(ll l, ll r) {
	return sum2(r) - sum2(l - 1);
}

typedef class TrieNode {
	public:
		bool cov;
		TrieNode* ch[2];
} TrieNode;

TrieNode pool[62 * 205 * 4];
TrieNode* _top = pool;

TrieNode* newnode() {
	_top->cov = false;
	_top->ch[0] = _top->ch[1] = NULL;
	return _top++;
}

void insert(TrieNode* &p, ll l, ll r, ll ql, ll qr) {
	if (!p) {
		p = newnode();	
	}
	if (l == ql && r == qr) {
		p->cov = true;
		return;
	}
	ll mid = (l + r) >> 1;
	if (qr <= mid) {
		insert(p->ch[0], l, mid, ql, qr);
	} else if (ql > mid) {
		insert(p->ch[1], mid + 1, r, ql, qr);
	} else {
		insert(p->ch[0], l, mid, ql, mid);
		insert(p->ch[1], mid + 1, r, mid + 1, qr);
	}
}

ll solve(vector<pair<TrieNode*, TrieNode*>> a, ll l, ll r) {
	if (a.empty()) {
		return 0;
	}
	for (auto t : a) {
		if (t.first->cov || t.second->cov) {
			return sum2(r) - sum2(l - 1);
		}
	}
	vector<pair<TrieNode*, TrieNode*>> b[2];
	for (auto t : a) {
		auto x = t.first;
		auto y = t.second;
		for (int bx = 0; bx < 2; bx++) {
			for (int by = 0; by < 2; by++) {
				if (x->ch[bx] && y->ch[by]) {
					b[bx ^ by].emplace_back(x->ch[bx], y->ch[by]);
				}
			}
		}
	}
	ll mid = (l + r) >> 1;
	ll foo = solve(b[0], l, mid);
	ll baz = solve(b[1], mid + 1, r);
	return foo + baz;
}

int na, nb;
TrieNode *rta, *rtb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll R = (1ll << bzmax) - 1, l, r;
	cin >> na;
	for (int i = 0; i < na; i++) {
		cin >> l >> r;
		insert(rta, 0, R, l, r);
	}
	cin >> nb;
	for (int i = 0; i < nb; i++) {
		cin >> l >> r;
		insert(rtb, 0, R, l, r);
	}
	ll ans = solve(vector<pair<TrieNode*, TrieNode*>> {make_pair(rta, rtb)}, 0, R);
	ans %= Mod;
	if (ans < 0) {
		ans += Mod;
	}
	cout << ans << '\n';
	return 0;
}