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

const int N = 1005;

int n;
char s[N];
boolean ban[N];
int cntl[N];

vector<int> find() {
	vector<int> pos;
	int l = 1, r = n;
	while (l <= r) {
		while (l <= r && (ban[l] || s[l] != '('))
			l++;
		while (r >= l && (ban[r] || s[r] != ')'))
			r--;
		if (l <= r) {
			pos.pb(l);
			pos.pb(r);
			ban[l] = ban[r] = true;
			l++, r--;
		}
	}
	return pos;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	vector<vector<int>> ans;
	vector<int> tmp;
	while (!(tmp = find()).empty()) {
		sort(tmp.begin(), tmp.end());
		ans.pb(tmp);
	}
	cout << ans.size() << '\n';
	for (auto& v : ans) {
		cout << v.size() << '\n';
		for (auto& x : v) {
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}