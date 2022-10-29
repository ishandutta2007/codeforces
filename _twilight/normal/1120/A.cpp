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

const int N = 5e5 + 5;

int m, n, k, s;
int a[N], b[N];

int main() {
	scanf("%d%d%d%d", &m, &k, &n, &s);
	for (int i = 1; i <= m; i++) {
		scanf("%d", a + i);
	}
	int rest = 0;
	for (int i = 1, x; i <= s; i++) {
		scanf("%d", &x);
		rest += !b[x];
		b[x]++;
	}
	
	auto mdf = [&] (int idx, int dlt) {
		rest -= b[idx] > 0;
		b[idx] += dlt;
		rest += b[idx] > 0;
	};

	for (int l = 1, r = 1; l + k - 1 <= m; mdf(a[l++], 1)) {
		while (r <= m && rest) {
			mdf(a[r++], -1);
		}
		if (rest)
			break;
		if (m - ((l - 1) % k) - max(r - l - k, 0) >= n * k) {
			for (int i = l; i < r; i++)
				mdf(a[i], 1);
			int other = k - s, put = 0;
			vector<int> S;
			for (int i = 0; i < ((l - 1) % k); i++)
				S.push_back(i + 1);
			for (int i = l; i <= m && put < k; i++) {
				if (b[a[i]]) {
					--b[a[i]];
					put++;
				} else if (other) {
					put++;
					other--;
				} else {
					S.push_back(i);
				}
			}
			printf("%d\n", (signed) S.size());
			for (auto e : S)
				printf("%d ", e);
			return 0;
		}
	}
	puts("-1");
	return 0;
}