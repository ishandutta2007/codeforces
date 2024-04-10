#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

int MOD =  1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 300000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

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
        return find_set(parent[v]);
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

int n, l, r;

int calc(int up, int down, int both, int need)
{
    if (up + down + both < n) return 0;
    int x1 = need; int x2 = n - need;
    if (up>x1) return 0; if (down>x2) return 0;
    x1-=up; x2-=down;
    return C(both, x1);
}

int calc(int up, int down, int both)
{
    //cout<<up<<' '<<down<<' '<<both<<endl;
    if (n%2==0) return calc(up, down, both, n/2);
    else return add(calc(up, down, both, n/2), calc(up, down, both, (n+1)/2));
}

void solve()
{
    cin>>n>>l>>r;
    l--; r--;

    int total = 0;

    map<int, int> eq, both_to_down, both_to_up, up_to_no, down_to_no;

    for (int i = 0; i<n; i++)
    {
        int l1 = l-i; int r1 = r-i;
        if ((-l1)==r1)
        {
            eq[r1+1]++;
        }
        else
        {
            if (r1>(-l1))
            {
                both_to_up[(-l1)+1]++;
                up_to_no[r1+1]++;
            }
            else
            {
                both_to_down[r1+1]++;
                down_to_no[(-l1)+1]++;

            }
        }
    }

    int st = 1e9;
    for (int i = 0; i<n; i++) st = min(st, min(r-i, -(l-i)));

    total = add(total, mul(st, calc(0, 0, n)));
    int down = 0; int up = 0; int both = n;
    for (int i = st+1; i<=st+n; i++)
    {
        both-=eq[i];

        both-=both_to_down[i];
        down+=both_to_down[i];

        both-=both_to_up[i];
        up+=both_to_up[i];

        up-=up_to_no[i];

        down-=down_to_no[i];

        total = add(total, calc(up, down, both));
    }
    cout<<total<<endl;
}

/*
 (a_i - i) = - (a_j - j)

 So, there is some k, and half of the numbers are i+k, half are i-k

 [l, r], [l-1, r-1], ..., [l-(n-1), r-(n-1)]

 Want to know what exactly??? Number of such k that...



 */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    int t; cin>>t; while (t--) solve();


}

/*
 1
3 0 3
 */