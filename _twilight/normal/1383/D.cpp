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

typedef class Data {
  public:
    int x, y;

    Data() {  }
    Data(int x, int y) : x(x), y(y) {  }
} Data;

const int N = 255;

int n, m;
int w, h;
queue<Data> Q;
int mxc[N], mxr[N];
bool inq[N][N];
int a[N][N], b[N][N];
bool iscmx[N * N], isrmx[N * N];

bool chk(int x, int y) {
  if (x >= 1 && y >= 1 && x <= w && y <= h && !b[x][y] && !inq[x][y]) {
    if (!b[x][y + (mxr[x] < y ? -1 : 1)]) return false;
    if (!b[x + (mxc[y] < x ? -1 : 1)][y]) return false;
    inq[x][y] = true;
    Q.push(Data(x, y));
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= m; j++) {
      vmax(mx, a[i][j]);
    }
    isrmx[mx] = true;
  }
  for (int j = 1; j <= m; j++) {
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      vmax(mx, a[i][j]);
    }
    iscmx[mx] = true;
  }
  for (int i = n * m; i; i--) {
    if (isrmx[i] && iscmx[i]) {
      ++w, ++h;
      b[w][h] = i;
      mxr[w] = h;
      mxc[h] = w;
      chk(w - 1, h);
      chk(w, h - 1);
    } else if (isrmx[i]) {
      ++w;
      b[w][h] = i;
      mxr[w] = h;
      chk(w, h - 1);
    } else if (iscmx[i]) {
      ++h;
      b[w][h] = i;
      mxc[h] = w;
      chk(w - 1, h);
    } else {
      assert(!Q.empty());
      int x = Q.front().x, y = Q.front().y;
      Q.pop();
      b[x][y] = i;
      chk(x - 1, y);
      chk(x, y - 1);
      chk(x + 1, y);
      chk(x, y + 1);
    }
  }
  assert(w == n && h == m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d%c", b[i][j], (j == m) ? '\n' : ' ');
    }
  }
  return 0;
}