#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

#define vi vector<int>


using ll = long long;
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
/*
int p = 1e9 + 7;


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
    a.resize(r);
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

void solve()
{
    int n;
    cin>>n;
    vector<int> a(3);
    map<pair<int, int>, int> m;
    map<pair<int, int>, vector<int>> which;
    map<pair<int, int>, bool> edge;

    vector<vector<int>> q(n-2, vector<int>(3));

    for (int i = 0; i<n-2; i++)
    {
        for (int j = 0; j<3; j++) cin>>q[i][j];
        for (int x = 0; x<3; x++)
            for (int y = 0; y<3; y++) if (x!=y)
                {
                    m[mp(q[i][x], q[i][y])]++;
                    which[mp(q[i][x], q[i][y])].push_back(i);
                }
    }



    vector<pair<int, pair<int, int>>> lol;

    for (auto it: m)
    {
        lol.push_back(mp(it.second, it.first));
    }
    sort(lol.begin(), lol.end());
    vector<vector<int>> G(n+1);
    for (int i = 0; i<2*n; i++) G[lol[i].second.first].push_back(lol[i].second.second);
    vector<int> prm = {1, G[1][0]};
    for (int i = 2; i<n; i++)
    {
        prm.push_back(G[prm[i-1]][0] + G[prm[i-1]][1] - prm[i-2]);
    }

    vector<int> dp(n-2);

    for (int i = 0; i<n; i++)
    {
        edge[mp(prm[i], prm[(i+1)%n])] = true;
        edge[mp(prm[(i+1)%n], prm[i])] = true;
        for (auto it: which[mp(prm[i], prm[(i+1)%n])])
        {
            dp[it]++;
        }
    }

    set<pair<int, int>> kek;
    for (int i = 0; i<n-2; i++) kek.insert(mp(dp[i], i));

    vector<int> ord;

    for (int i = 0; i<n-2; i++)
    {
        /*for (auto it: kek)
        {
            cout<<it.first<<' '<<it.second<<endl;
        }
        cout<<endl;*/
        auto it = *prev(kek.end());
        int idx = it.second;
        int X, Y;

        for (int x = 0; x<3; x++)
            for (int y = 0; y<3; y++) if (x!=y && !edge[mp(q[idx][x], q[idx][y])]) {X = q[idx][x]; Y = q[idx][y];}
        ord.push_back(idx);


        for (auto it: which[mp(X, Y)])
        {
            kek.erase(mp(dp[it], it));
            dp[it]++;
            kek.insert(mp(dp[it], it));
        }
        kek.erase(mp(dp[idx], idx));
        edge[mp(X, Y)] = true;
        edge[mp(Y, X)] = true;
    }
    for (auto it: prm) cout<<it<<' ';
    cout<<endl;
    for (auto it: ord) cout<<it+1<<' ';
    cout<<endl;


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();

}

/*
1
6
2 5 6
2 5 1
4 1 2
1 3 5
 */