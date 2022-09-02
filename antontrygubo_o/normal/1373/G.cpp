#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


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


mt19937 rnd(time(0));




/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{*
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

const int INF = 1e9;

const int N = 2e6;
vector<int> t(N), lazy(N);

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int n, k, m;

int produce(int x, int y)
{
    return y + abs(x- k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>k>>m;

    multiset<int> a;

    set<pair<int, int>> pawns;

    for (int i = 0; i<2*n; i++) update(1, 0, 2*n-1, i, i, i);

    for (int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        y--;
        int h = produce(x, y);
        //cout<<x<<' '<<y<<": "<<h<<endl;
        if (pawns.count(mp(x, y)))
        {
            update(1, 0, 2*n-1, 0, h, -1);
            pawns.erase(mp(x, y));
            a.erase(a.find(h));
        }
        else
        {
            update(1, 0, 2*n-1, 0, h, 1);
            pawns.insert(mp(x, y));
            a.insert(h);
        }

        int need = 0;
        if (a.size()>0) need = query(1, 0, 2*n-1, 0, *prev(a.end()));
        cout<<max(0, need - n)<<endl;
    }
}

/*
1
4
4 5 2 3
2 3 2 7
 */