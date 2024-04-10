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


/*const int LIM = 1e6 + 5;

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


void solve()
{
    string x, y;
    cin>>x>>y;

    int n = x.size(); int m = y.size();

    vector<int> good_x(n, 1), good_y(m, 1);
    for (int i = 0; i<n; i++)
    {
        while (i+good_x[i]<n && x[i+good_x[i]]!=x[i+good_x[i]-1]) good_x[i]++;
    }

    for (int i = 0; i<m; i++)
    {
        while (i+good_y[i]<m && y[i+good_y[i]]!=y[i+good_y[i]-1]) good_y[i]++;
    }

    vector<vector<int>> dp_x(n, vector<int>(m)), dp_y(n, vector<int>(m));

    for (int i = n-1; i>=0; i--)
        for (int j = m-1; j>=0; j--)
        {
            //Case 1: starting from x

            if (x[i]!=y[j]) dp_x[i][j] = add(dp_x[i][j], good_y[j]);

            if (i+1<n && x[i]!=x[i+1]) dp_x[i][j] = add(dp_x[i][j], dp_x[i+1][j]);
            if (i+1<n && x[i]!=y[j]) dp_x[i][j] = add(dp_x[i][j], dp_y[i+1][j]);

            //Case 2: starting from y

            if (y[j]!=x[i]) dp_y[i][j] = add(dp_y[i][j], good_x[i]);

            if (j+1<m && y[j]!=y[j+1]) dp_y[i][j] = add(dp_y[i][j], dp_y[i][j+1]);
            if (j+1<m && x[i]!=y[j]) dp_y[i][j] = add(dp_y[i][j], dp_x[i][j+1]);

        }
    int ans = 0;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) ans = add(ans, add(dp_x[i][j], dp_y[i][j]));

    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);



    int t = 1; while (t--) solve();


}

/*
1
1100
 */