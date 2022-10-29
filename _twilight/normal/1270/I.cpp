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

int k, m, N;
int dx[100], dy[100];
ll a[512][512], b[512][512];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> k;
  N = 1 << k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> dx[i] >> dy[i];
  }
  for (int i = 0; i < k; i++) {
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        for (int t = 0; t < m; t++) {
          b[(x + dx[t]) & (N - 1)][(y + dy[t]) & (N - 1)] ^= a[x][y];
        }
      }
    }
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        a[x][y] = b[x][y];
        b[x][y] = 0;
      }
    }
    for (int t = 0; t < m; t++) {
      (dx[t] <<= 1) &= (N - 1);
      (dy[t] <<= 1) &= (N - 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += !!a[i][j];
    }
  }
  cout << ans << '\n';
  return 0;
}