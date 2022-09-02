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
    vector<int> value;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        value[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        else
        {
            auto par = find_set(parent[v]);
            value[v]^=value[parent[v]];
            parent[v] = par;
            return par;
        }
    }

    void union_sets(int a, int b, int w) {
        find_set(a);
        find_set(b);

        w^=value[a]; w^=value[b];
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            value[b] = w;
            sz[a] += sz[b];
        }
    }

    int val(int v)
    {
        find_set(v); return value[v];
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        value.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

int n;
vector<vector<int>> a;

vector<pair<int, int>> edges;


vector<int> vals;
int idx;


int solve(vector<int> cur)
{

    //cout<<"Solving for: "; for (auto it: cur) cout<<it<<' '; cout<<endl;

    if (cur.size()==1)
    {
        vals[cur[0]] = a[cur[0]][cur[0]];
        return cur[0];
    }

    int maxx = 0;
    int k = cur.size();
    for (int i = 0; i<k; i++)
        for (int j = 0; j<k; j++) maxx = max(maxx, a[cur[i]][cur[j]]);

    vals.push_back(maxx);

    int cur_idx = idx;
    idx++;


    vector<vector<int>> vecs;
    for (auto it: cur)
    {
        bool found = false;
        for (auto &vec: vecs)
        {
            if (a[vec.back()][it] < maxx)
            {
                found = true; vec.push_back(it); break;
            }
        }
        if (!found)
        {
            vecs.push_back({it});
        }
    }

    for (auto vec: vecs)
    {
        int son_idx = solve(vec);
        edges.push_back(mp(son_idx, cur_idx));
    }


    return cur_idx;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;

    idx = n;
    vals.resize(n);

    a = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++) cin>>a[i][j];
    }

    vector<int> guys(n); for (int i = 0; i<n; i++) guys[i] = i;

    int root = solve(guys);

    cout<<vals.size()<<endl;
    for (auto it: vals) cout<<it<<' ';
    cout<<endl;
    cout<<root+1<<endl;
    for (auto it: edges) cout<<it.first+1<<' '<<it.second+1<<endl;






}