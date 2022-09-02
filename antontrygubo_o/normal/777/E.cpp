#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX*/

using namespace __gnu_pbds;
using namespace std;

#define vi vector<int>


using ll = long long;
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
/*
const int p = 998244353;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}
*/

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

mt19937 rnd(time(0));

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
}

int lds(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n);
    int ans = 1;
    dp[n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        for (int j = i+1; j<n; j++) if (a[i]>a[j]) dp[i] = max(dp[i], dp[j]+1);
        ans = max(ans, dp[i]);
    }
    return ans-1;
}

int solve2(vector<int> a)
{
    return lds(a);
}

bool check(int n)
{
    vector<int> a;
    for (int i = 1; i<=n; i++) a.push_back(i);
    do
    {
        if (solve1(a)!=solve2(a)) {for (auto it: a) cout<<it<<' '; cout<<endl; cout<<"Expected "<<solve1(a)<<endl; cout<<"Got "<<solve2(a)<<endl; return 0;}
    }while (next_permutation(a.begin(), a.end()));
    cout<<"OK"<<endl;
}a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++) {
        a[j] = mul(a[j], b[j]);
    }
    fft(a, true);
    while (!a.empty() && (a.back() == 0)) a.pop_back();
}

*/

struct FenwickTreeMax {
    vector<ll> bit;
    int n;
    //const int INF = (int)1e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, 0);
    }


    ll getmax(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, ll val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> h(n);
    for (int i = 0; i<n; i++) cin>>a[i]>>b[i]>>h[i];

    set<int> kek;
    for (auto it: a) kek.insert(it);
    for (auto it: b) kek.insert(it);
    map<int, int> mapka;
    int cur = 0;
    for (auto it: kek)
    {
        mapka[it] = cur;
        cur++;
    }
    for (int i = 0; i<n; i++) a[i] = mapka[a[i]];
    for (int i = 0; i<n; i++) b[i] = mapka[b[i]];


    //cout<<"GOOD"<<endl;

    vector<pair<pair<int, int>, int>> t1(n);
    for (int i = 0; i<n; i++) t1[i] = mp(mp(-b[i], a[i]), h[i]);
    sort(t1.begin(), t1.end());

    vector<pair<pair<ll, ll>, ll>> t(1);
    t[0] = t1[0];
    for (int i = 1; i<n; i++)
    {
        if (t1[i].first.first!=t1[i-1].first.first) t.push_back(t1[i]);
        else
        {
            t[t.size()-1].second += t1[i].second;
        }
    }

    //cout<<"GOOD"<<endl;

    FenwickTreeMax F(1e6);

    ll maxx = 0;

    //for (auto it: t) cout<<-it.first.first<<' '<<it.first.second<<' '<<it.second<<endl;

    for (int i = 0; i<t.size(); i++)
    {
        ll res = F.getmax(-t[i].first.first-1);
        F.update(t[i].first.second, res + t[i].second);
        //cout<<res<<endl;
        maxx = max(maxx, res + t[i].second);
    }
    cout<<maxx;

}

/*
3
1 5 1
2 6 2
3 7 3
 */