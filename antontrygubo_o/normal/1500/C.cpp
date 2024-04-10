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


const int MOD =  998244353;

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
const int LIM = 1e6 + 5;

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
        else
        {
            auto par = find_set(parent[v]);
            parent[v] = par;
            return par;
        }
    }

    void union_sets(int a, int b) {
        find_set(a);
        find_set(b);

        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) cin>>a[i][j];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) cin>>b[i][j];


    vector<int> inversions(m);

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n-1; j++) if (b[j][i]>b[j+1][i]) inversions[i]++;
    }

    vector<int> order;

    vector<bool> broke(n-1);
    vector<bool> used(m);

    while (true)
    {
        int idx = -1;
        for (int i = 0; i<m; i++) if (!used[i] && inversions[i]==0) idx = i;

        if (idx==-1) break;

        order.push_back(idx);
        used[idx] = true;
        for (int i = 0; i<n-1; i++) if (!broke[i] && b[i][idx]<b[i+1][idx])
        {
            broke[i] = true;
            for (int j = 0; j<m; j++) if (b[i][j]>b[i+1][j]) inversions[j]--;
        }
    }

    reverse(order.begin(), order.end());

    vector<int> row(n);
    for (int i = 0; i<n; i++) row[i] = i;

    for (auto it: order)
    {
        vector<pair<int, int>> new_row(n);
        for (int i = 0; i<n; i++) new_row[i] = mp(a[row[i]][it], i);
        sort(new_row.begin(), new_row.end());

        for (int i = 0; i<n; i++) new_row[i].second = row[new_row[i].second];

        for (int i = 0; i<n; i++) row[i] = new_row[i].second;
    }

    bool check = true;

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) if (b[i][j] != a[row[i]][j]) check = false;
    }

    if (check)
    {
        cout<<order.size()<<endl; for (auto it: order) cout<<it+1<<' ';
    }
    else cout<<-1;
}
/*

 */

/*

1 1 2
1 3 3
2 3 2
 */