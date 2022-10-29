#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
      printf("%s", ++it == end ? closing : separator));
}

const int N = 2e5+5;
int n, m;
ll l[N], r[N], a[N];

typedef pair<ll, int> pli;
pli c[2*N];
priority_queue<pli> q;

int b[N];

bool solve() {
  int k = m + n - 1;
  sort(c, c+k);
  REP(i, k) {
    if (c[i].Y < 0) {
      int j = -c[i].Y;
      q.emplace(l[j-1] - r[j], j);
    } else if (!q.empty()) {
      if (-q.top().X < c[i].X) return false;
      b[q.top().Y] = c[i].Y + 1;
      q.pop();
    }
  }
  return q.empty();
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  cin >> n >> m;
  REP(i, n) cin >> l[i] >> r[i];
  REP(i, m) {
    cin >> c[i].X;
    c[i].Y = i;
  }
  FOR(i, 1, n) c[m+i-1] = {l[i] - r[i-1], -i};
  if (solve()) {
    printf("Yes\n");
    print("%d", b+1, b+n);
  } else {
    printf("No\n");
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}