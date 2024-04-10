#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

using namespace __gnu_pbds;
using namespace std;

#define vi vector<int>


using ll = long long;

#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;



vector<int> Z(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

//******CONVEX HULL TRICK******//

/*
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a /b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
        isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
*/


//******MAXFLOW******//

/*
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow {
  int N;
  VVI cap, flow;
  VI dad, Q;

  MaxFlow(int N) :
    N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    this->cap[from][to] += cap;
  }

  int BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), -1);
    dad[s] = -2;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < N; i++) {
        if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0) {
          dad[i] = x;
          Q[tail++] = i;
        }
      }
    }

    if (dad[t] == -1) return 0;

    int totflow = 0;
    for (int i = 0; i < N; i++) {
      if (dad[i] == -1) continue;
      int amt = cap[i][t] - flow[i][t];
      for (int j = i; amt && j != s; j = dad[j])
        amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
      if (amt == 0) continue;
      flow[i][t] += amt;
      flow[t][i] -= amt;
      for (int j = i; j != s; j = dad[j]) {
        flow[dad[j]][j] += amt;
        flow[j][dad[j]] -= amt;
      }
      totflow += amt;
    }

    return totflow;
  }

  int GetMaxFlow(int source, int sink) {
    int totflow = 0;
    while (int flow = BlockingFlow(source, sink))
      totflow += flow;
    return totflow;
  }
};*/


//******DSU******//


/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

//******MODULAR FFT******//

/*
const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;


void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % p);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % p);
                a[i+j] = u+v < p ? u+v : u+v-p;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+p;
                w = int (w * 1ll * wlen % p);
            }
        }
    }
    if (invert) {
        int nrev = po(n, p - 2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % p);
    }
}
void poly_mult(vector < int >& a, vector < int > b) {
    int s = a.size() + b.size();
    int r = 1;
    while (r < s) r *= 2;
    int solve1(vector<int> a)
{
    int n = a.size();
    int cnt = 0;
    vector<int> b;
    vector<int> c;
    while (true)
    {
        int maxx = 0;
        for (int i = 0; i<n; i++)
        {
            if (a[i]>maxx) b.push_back(a[i]);
            else c.push_back(a[i]);
            maxx = max(maxx, a[i]);
        }
        if (b.size()==n) break;
        cnt++;
        a.clear();
        for (auto it: c) a.push_back(it);
        for (auto it: b) a.push_back(it);
        b.clear();
        c.clear();
    }
    return cnt;
}*/
/*
void solve()
{
    int n;
    cin>>n;

    vector<int> l(n), r(n);
    for (int i = 0; i<n; i++) cin>>l[i]>>r[i];

    set<int> ls, rs;
    for (auto it: l) ls.insert(it);
    for (auto it: r) rs.insert(it);

    map<int, int> forleft, forright;
    for (auto it: ls) forleft[it] = -1e9;
    for (auto it: rs) forright[it] = 1e9;

    for (int i = 0; i<n; i++) forleft[l[i]] = max(forleft[l[i]], r[i]);
    for (int i = 0; i<n; i++) forright[r[i]] = max(forright[r[i]], l[i]);


    vector<pair<int, int>> L, R;
    for (auto it: forleft) L.push_back(it);
    for (auto it: forright) R.push_back(it);

    int A = L.size();
    int B = R.size();

    int cntL = 0;

    ordered_set right_ends;

    ll answer = 0;

    for (auto x: R)
    {
        while (cntL<A && L[cntL].first<x.first)
        {
            right_ends.insert(mp(L[cntL].second, L[cntL].first));
            cntL++;
        }
        answer =
    }

}*/

void solve()
{
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    const int N = 100;
    vector<int> free(N);
    vector<int> Y(N);
    vector<int> Z(N);

    for (int i = 1; i<N; i++)
    {
        set<int> setfree;
        setfree.insert(free[max(0, i-x)]);
        setfree.insert(Y[max(0, i-y)]);
        setfree.insert(Z[max(0, i-z)]);
        while (setfree.find(free[i])!=setfree.end()) free[i]++;

        set<int> sety;
        sety.insert(free[max(0, i-x)]);
        sety.insert(Z[max(0, i-z)]);
        while (sety.find(Y[i])!=sety.end()) Y[i]++;

        set<int> setz;
        setz.insert(free[max(0, i-x)]);
        setz.insert(Y[max(0, i-y)]);
        while (setz.find(Z[i])!=setz.end()) Z[i]++;
    }

    /*for (int i = 0; i<N; i++) cout<<free[i]<<' ';
    cout<<endl;
    for (int i = 0; i<N; i++) cout<<Y[i]<<' ';
    cout<<endl;
    for (int i = 0; i<N; i++) cout<<Z[i]<<' ';
    cout<<endl;*/


    int period = 0;
    while (true)
    {
        period++;
        bool check = true;
        for (int i = N/2; i+period<N; i++) if (free[i+period]!=free[i]||Y[i+period]!=Y[i]||Z[i+period]!=Z[i])
            {
                check = false; break;
            }
        if (check) break;
    }

    int cnt = 0;

    int res = 0;

    for (int i = 0; i<n; i++)
    {
        if (a[i]<N/2) res^=free[a[i]];
        else res^=free[(a[i]%period) + (70 - 70%period)];
    }

    for (int i = 0; i<n; i++)
    {
        ll cur;
        if (a[i]<N/2) cur = free[a[i]];
        else cur = free[(a[i]%period) + (70 - 70%period)];

        ll temp; int kek;
        temp = max(0ll, a[i] - x);
        if (temp<N/2) kek = free[temp];
        else kek = free[(temp%period) + (70 - 70%period)];

        if ((kek^cur)==res) cnt++;

        temp = max(0ll, a[i] - y);
        if (temp<N/2) kek = Y[temp];
        else kek = Y[(temp%period) + (70 - 70%period)];

        if ((kek^cur)==res) cnt++;

        temp = max(0ll, a[i] - z);
        if (temp<N/2) kek = Z[temp];
        else kek = Z[(temp%period) + (70 - 70%period)];

        if ((kek^cur)==res) cnt++;
    }
    cout<<cnt<<endl;

    /*for (int i = 0; i<N; i++)
    {
        cout<<i<<": "<<free[i]<<' '<<Y[i]<<' '<<Z[i]<<endl;
    }*/

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();





}

/*
1
2 1 3 4
7 6
 */