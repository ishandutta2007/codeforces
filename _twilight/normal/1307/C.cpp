#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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

#define ll long long

int n;
int cnt[26];
ll cnt2[26];
char s[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	ll ans = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
		cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		vmax(ans, (ll) cnt[i]);
		vmax(ans, 1ll * cnt[i] * (cnt[i] - 1) / 2);
	}
	for (int c = 0; c < 26; c++) {
		memset(cnt, 0, sizeof(cnt));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 1; i <= n; i++) {
			if (s[i] - 'a' == c) {
				for (int j = 0; j < 26; j++)
					cnt2[j] += cnt[j];
			}
			cnt[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
			vmax(ans, cnt2[i]);
	}
	printf("%lld\n", ans);
	return 0;
}