#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:134217728")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;
typedef vector <ll> vll;
typedef vector <vll> vvll;

const ld EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

__int32 main()
{
#ifdef LOCALFILE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  IOboost;

  int n;
  cin >> n;
  map <pair <string, int>, map <string, int>> g;
  pair<string, int> root;
  fi(n){
    int a;
    string str;
    cin >> str >> a;
    if (i == 0)
      root = mp(str, a);
    int k;
    cin >> k;
    fj(k){
      string s;
      int b;
      cin >> s >> b;
      if (g[mp(str, a)].find(s) != g[mp(str, a)].end()) {
        g[mp(str, a)][s] = max(g[mp(str, a)][s], b);
      }
      else
        g[mp(str, a)][s] = b;
    }
  }

  vector<string> ans;
  map<string, int> v;
  map<string, int> d;
  queue<string> q;
  q.push(root.F);
  v[root.first] = root.S;
  d[root.first] = 0;
  while (!q.empty()) {
    root = mp(q.front(), d[q.front()]);
    q.pop();
    for (auto i : g[mp(root.first, v[root.first])]) {
      if (v.find(i.first) == v.end()) {
        ans.pb(i.first);
        d[i.first] = root.second + 1;
        v[i.first] = i.second;
        q.push(i.first);
      }
      if (d[i.first] == root.second + 1 && v[i.first] < i.second) {
        v[i.first] = i.second;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto i : ans)
    cout << i << ' ' << v[i] << endl;

  return 0;
}