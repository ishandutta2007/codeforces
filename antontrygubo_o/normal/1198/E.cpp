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

#define ll long long
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


const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
    s = s%p;
    if (s<0) s+=p;
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
        return a / b - ((a ^ b) < 0 && a % b); }
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

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000001;

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
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    if (m==0) {cout<<0; return 0;}
    vector<vector<int>> a(m, vector<int>(4));
    for (int i = 0; i<m; i++) cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];

    set<int> l;
    for (int i = 0; i<m; i++)
    {
        l.insert(a[i][0]-1);
        l.insert(a[i][2]);
    }
    set<int> r;
    for (int i = 0; i<m; i++)
    {
        r.insert(a[i][1]-1);
        r.insert(a[i][3]);
    }

    /*for (auto it: l) cout<<it<<' ';
    cout<<endl;
    for (auto it: r) cout<<it<<' ';
    cout<<endl;*/

    auto flow = MaxFlow(205);
    vector<int> left;
    for (auto it: l) left.push_back(it);
    vector<int> right;
    for (auto it: r) right.push_back(it);

    int L = left.size();
    int R = right.size();


    for (int i = 0; i<L-1; i++)
    {
        flow.AddEdge(0, i+1, left[i+1] - left[i]);
    }

    for (int i = 0; i<R-1; i++)
    {
        flow.AddEdge(i+101, 204, right[i+1] - right[i]);
    }

    for (int i = 0; i<L-1; i++)
        for (int j = 0; j<R-1; j++)
        {
            bool check = false;
            for (int k = 0; k<m; k++)
            {
                if (left[i]+1>=a[k][0] && left[i+1]<=a[k][2] && right[j]+1>=a[k][1] && right[j+1]<=a[k][3]) check = true;
            }
            if (check)
            {
                //cout<<i<<' '<<j<<": "<<min(left[i+1]-left[i], right[j+1]-right[j])<<endl;
                flow.AddEdge(i+1, j+101, min(left[i+1]-left[i], right[j+1]-right[j]));
            }
        }

    cout<<flow.GetMaxFlow(0, 204);
}