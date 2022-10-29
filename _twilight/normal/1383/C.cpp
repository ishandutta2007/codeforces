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
int discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 1e5 + 5;

int T, n;
char s[N], t[N];
int G0[22], G[22];
int uf[22];

int find(int x) {
  return uf[x] == x ? x : (uf[x] = find(uf[x]));
}
void unit(int x, int y) {
  x = find(x);
  y = find(y);
  if (x ^ y) {
    uf[x] = y;
  }
}

int solve(vector<int> p) {
  memset(G, 0, sizeof(G));
  int n = p.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((G0[p[i]] >> p[j]) & 1) {
        G[i] |= (1 << j);
      }
    }
  }
  vector<bool> dp (1 << n, 0);
  dp[0] = true;
  int res = 0;
  for (int s = 0; s < (1 << n); s++) {
    if (!dp[s]) continue;
    res = max(res, __builtin_popcount(s));
    for (int i = 0; i < n; i++) {
      if (!((s >> i) & 1) && !(G[i] & s)) {
        dp[s | (1 << i)] = true;
      }
    }
  }
  return 2 * n - 1 - res;
}

void solve() {
	cin >> n;
	string s, t;
	cin >> s;
	cin >> t;
	memset(G0, 0, sizeof(G0));
  for (int i = 0; i < 20; i++) {
    uf[i] = i;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      G0[s[i] - 'a'] |= 1 << (t[i] - 'a');
      unit(s[i] - 'a', t[i] - 'a');
    }
	}
  int ans = 0;
  for (int i = 0; i < 20; i++) {
    if (find(i) == i) {
      vector<int> p;
      for (int j = 0; j < 20; j++) {
        if (find(j) == i) {
          p.push_back(j);
        } 
      }
      ans += solve(p);
    }      
  }
  cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}