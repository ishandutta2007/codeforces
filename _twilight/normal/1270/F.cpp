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
void discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

const int N = 2e5 + 5;

int n, C;
char s[N];
ll ans;

void solve1() {
	vector<int> P1 {0};
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			P1.pb(i);
		}
	}
	for (int c = 1; c <= C && c < (signed) P1.size(); c++) {
		int t = P1.size();
		int pr = c - 1;
		for (int i = P1[c]; i <= n; i++) {
			if (pr < t && i == P1[pr + 1])
				pr++;
			int pl = P1[pr - c + 1];
			int p0 = P1[pr - c];
			int rest = (i - pl + 1) % c;
			if (rest)
				pl -= c - rest;
			if (pl > p0)
				ans += (pl - p0 + c - 1) / c; 
		}
	}
}

int s1[N];
int sum[N];
int buc[N << 1], id[N << 1];

void put(int s) {
	int x = (s % (n << 1));
	if (x < 0)
		x += (n << 1);
	if (id[x] ^ s) {
		id[x] = s;
		buc[x] = 1;
	} else {
		buc[x]++;
	}
}
int query(int s) {
	int x = (s % (n << 1));
	if (x < 0)
		x += (n << 1);
	if (id[x] ^ s)
		return 0;
	return buc[x];
}

void solve2() {
	for (int i = 1; i <= n; i++)
		s1[i] = s1[i - 1] + (s[i] == '1');
	for (int r = 1; r * (C + 1) <= n; r++) {
		memset(buc, 0, sizeof(int) * (n << 1));
		for (int i = 0; i < (n << 1); i++)
			id[i] = -(n << 1);
		int l = 1;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + ((s[i] == '1') ? (r - 1) : (-1));
			while (s1[i] - s1[l - 1] > C) {
				put(sum[l - 1]);
				l++;
			}
			ans += query(sum[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	C = sqrt(n + 0.5);
	solve1();
	solve2();
	cout << ans << '\n';
	return 0;
}