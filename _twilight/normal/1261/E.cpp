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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pii> a (n);
	vector<int> b (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi;
		a[i].sc = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		b[a[i].sc] = i;
	vector<vector<char>> s (n + 1, vector<char>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s[i][j] = (i != j) + '0'; 
		}
	}
	for (int i = 0; i < n; i++)
		s[n][i] = '1';
	for (int i = 0; i < n; i++) {
		int p = i + 1, r = n;
		while (r > a[i].fi) {
			if (p > n)
				p -= n + 1;
			s[p++][i] = '0';
			r--;
		}
	}	
	cout << n + 1 << '\n'; 
	vector<char> t (n + 1, 0);
	for (auto& v : s) {
		for (int i = 0; i < n; i++)
			t[i] = v[b[i]];
		cout << t.data() << '\n';
	}
	return 0;
}