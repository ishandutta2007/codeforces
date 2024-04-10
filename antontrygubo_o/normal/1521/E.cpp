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

/*
const int LIM = 1000;

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
}*/


/*struct DSU
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

int m, k;
vector<int> a;
vector<int> b;

void solve()
{
    cin>>m>>k;

    a.clear(); a.resize(k); for (int i = 0; i<k; i++) cin>>a[i];

    vector<pair<int, int>> guys;
    for (int i = 0; i<k; i++) guys.push_back(mp(a[i], i+1)); sort(guys.begin(), guys.end()); reverse(guys.begin(), guys.end());

    b.clear();
    for (auto it: guys)
    {
        for (int i = 0; i<it.first; i++) b.push_back(it.second);
    }

    int L = 1;
    int R = sqrt(4*m);

    if (m<=1)
    {
        cout<<1<<endl<<b[0]<<endl; return;
    }

    while (R-L>1)
    {
        int mid = (L+R)/2;

        int big = mid*((mid+1)/2);
        int tot = mid*mid - (mid/2)*(mid/2);
        if (guys[0].first<=big && m<=tot) R = mid;
        else L = mid;
    }

    int n = R;

    int big = n*((n+1)/2);
    int tot = n*n - (n/2)*(n/2);

    vector<pair<int, int>> gr1, gr2, gr3;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            if (i%2==0 && j%2==1) gr1.push_back(mp(i, j));
            if (i%2==1 && j%2==0) gr2.push_back(mp(i, j));
            if (i%2==0 && j%2==0) gr3.push_back(mp(i, j));
        }

    vector<pair<int, int>> cells;
    for (auto it: gr1) cells.push_back(it);
    for (auto it: gr3) cells.push_back(it);
    for (auto it: gr2) cells.push_back(it);

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i<m; i++) mat[cells[i].first][cells[i].second] = b[i];

    cout<<n<<endl;

    for (auto vec: mat)
    {
        for (auto x: vec) cout<<x<<' ';
        cout<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}

/*
1
7
1 2
1 3
2 4
2 5
3 6
3 7
 */