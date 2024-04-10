#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int MOD =  1e9 + 7;

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


const int LIM = 400005;

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

vector<int> answer(61);

vector<vector<bool>> can(6, vector<bool>(6, true));

pair<bool, ll> move_left(ll n)
{
    //cout<<"Processing "<<n<<endl;
    int deg = 60;
    while ((n&(1ll<<deg))==0) deg--;
    ll n1 = n - (1ll<<deg);
    if (n1&(1ll<<(deg-1)))
        return mp(false, n1);
    else
        return mp(true, n1+(1ll<<(deg-1)));
}

vector<int> solve(int depth, vector<pair<ll, int>> nodes)
{
    /*cout<<"Solving: "<<depth<<endl;
    for (auto it: nodes)
    {
        cout<<it.first<<' '<<it.second<<endl;
    }*/
    if (nodes.size()==0)
    {
        return vector<int>(6, answer[depth]);
    }

    if (depth==1)
    {
        vector<int> ans(6);
        ans[nodes[0].second] = 1;
        return ans;
    }

    int root_color = -1;

    vector<pair<ll, int>> left, right;
    for (auto it: nodes)
    {
        if (it.first==1)
        {
            root_color = it.second;
            continue;
        }
        auto dir = move_left(it.first);
        if (dir.first)
        {
            left.push_back(mp(dir.second, it.second));
        }
        else
        {
            right.push_back(mp(dir.second, it.second));
        }
    }

    auto solve1 = solve(depth-1, left);
    auto solve2 = solve(depth-1, right);

    vector<int> ans(6);
    for (int chleft = 0; chleft<6; chleft++)
        for (int chright = 0; chright<6; chright++)
            for (int ch = 0; ch<6; ch++)
            {
                if (root_color!=-1 && root_color!=ch) continue;
                if (!can[chleft][ch] || !can[chright][ch]) continue;
                ans[ch] = add(ans[ch], mul(solve1[chleft], solve2[chright]));
            }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 1; i<=60; i++) answer[i] = po(4, ((1ll<<i)-2));
    map<string, int> color;
    vector<pair<ll, int>> nodes;
    color["white"] = 0;
    color["yellow"] = 1;
    color["green"] = 2;
    color["blue"] = 3;
    color["red"] = 4;
    color["orange"] = 5;


    for (int i = 0; i<6; i++) can[i][i] = false;
    for (int i = 0; i<6; i++) can[i][i^1] = false;

    int k, n; cin>>k>>n;

    for (int i = 0; i<n; i++)
    {
        ll node; string col;
        cin>>node>>col;
        nodes.push_back(mp(node, color[col]));
    }

    auto ans = solve(k, nodes);

    int res = 0;
    for (auto it: ans) res = add(res, it);
    cout<<res<<endl;


}