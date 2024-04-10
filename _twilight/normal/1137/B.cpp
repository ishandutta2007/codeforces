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

const int N = 5e5 + 5;

int n, m;
char s[N], t[N], nt[N];
int f[N];

void count(char* s, int len, int& cnt0, int& cnt1) {
	cnt0 = cnt1 = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] == '0') {
			cnt0++;
		} else {
			cnt1++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	cin >> (t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++) {
		int j = f[i];
		while (j && t[j + 1] != t[i + 1])
			j = f[j];
		f[i + 1] = ((t[j + 1] == t[i + 1]) ? (j + 1) : 0);
	}
	int cnt1 = 0, cnt0 = 0;
	int tcnt1, tcnt0, ncnt1, ncnt0;
	count(s, n, cnt0, cnt1);
	count(t, m, tcnt0, tcnt1);
	if (cnt0 < tcnt0 || cnt1 < tcnt1) {
		cout << s + 1 << '\n';
		return 0;
	}
	cnt0 -= tcnt0;
	cnt1 -=
	   	tcnt1;
	string ans (t + 1);
	for (int i = f[m] + 1; i <= m; i++) {
		nt[i - f[m]] = t[i];
	}
	count(nt, m - f[m], ncnt0, ncnt1);
	while (cnt0 >= ncnt0 && cnt1 >= ncnt1) {
		cnt0 -= ncnt0;
		cnt1 -= ncnt1;
		ans += string(nt + 1);
	}
	while (cnt0--)
		ans += '0';
	while (cnt1--)
		ans += '1';
	cout << ans << '\n';
	return 0;
}