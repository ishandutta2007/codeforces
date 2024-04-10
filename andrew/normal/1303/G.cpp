#include <bits/stdc++.h>


#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 150100;
const ll inf = 1e8;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

const ll is_query = -(1LL << 62);
const ll Q = -(1LL << 62);

struct Line {
ll m, b;
  mutable function<const Line *()> succ;

  bool operator<(const Line &rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line *s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};

struct HullDynamic : public multiset<Line> {
  bool bad(const iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (x->b - y->b) * (long double) (z->m - y->m) >= (y->b - z->b) * (long double) (y->m - x->m);
  }

  void insert_line(ll m, ll b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }

  ll eval(ll x) {
    auto l = *lower_bound((Line) {
      x, is_query
    });
    return l.m * x + l.b;
  }
};


struct need{
    ll up, down, sum, deep;
};

ll a[MAXN];

vector <need> v;
vector <int> g[N];
int stn[N], S, kol[N];
bool f[N], fl;

ll ans = 0;

need mb;

inline void paint(int x, int pr, int &centroid, int deep, ll s_up, ll s_down, ll sum, HullDynamic &F, ll mb_ans = 0){
    sum += a[x];
    s_down += sum;
    s_up += deep * a[x];
    mb_ans += (deep + 1) * a[x];
    ans = max(ans, mb_ans);

    bool is_leaf = 1;

    for(int to : g[x])if(to != pr && !f[to]){
        is_leaf = 0;
        paint(to, x, centroid, deep + 1, s_up, s_down, sum, F, mb_ans);
        if(x == centroid){
            if(fl){
                for(auto j : v){
                    ans = max(ans, j.down + F.eval(j.deep + 1));
                }
            }
            fl = 1;
            for(auto j : v){
                ans = max(ans, j.down);
                ans = max(ans, j.up);
                F.insert_line(j.sum - a[centroid], j.up);
            }
            v.clear();
        }
    }
    if(is_leaf){
        mb.up = s_up;
        mb.down = s_down;
        mb.sum = sum;
        mb.deep = deep;
        v.p_b(mb);
    }
}


inline int find_centroid(int x, int pr, int &centroid){
    int sz = 1;
    for(int to : g[x])if(to != pr && !f[to]){
        sz += find_centroid(to, x, centroid);
    }

    if(centroid == -1 && (!pr || (sz << 1) > S))centroid = x;

    return sz;
}

inline void build_centroid(int x, int sz){
    S = sz;
    int centroid = -1;
    find_centroid(x, 0, centroid);
    HullDynamic F;
    fl = 0;
    paint(centroid, 0, centroid, 0, 0, 0, 0, F);
    reverse(all(g[centroid]));
    HullDynamic C;
    fl = 0;
    paint(centroid, 0, centroid, 0, 0, 0, 0, C);
    f[centroid] = 1;
    for(int to : g[centroid])if(!f[to])build_centroid(to, sz >> 1);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        g[a].p_b(b);
        g[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)cin >> a[i];

    build_centroid(1, n);

    cout << ans << "\n";

    return 0;
}