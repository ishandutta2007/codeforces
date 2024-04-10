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

//vector<int> a = {2, 5, 3, 4, 1};

int ask(int t, int i, int j, int x)
{
    cout<<"? "<<t<<' '<<i+1<<' '<<j+1<<' '<<x<<endl;

    /*if (t==1) return max(min(a[i], x), min(a[j], x+1));
    else  return min(max(a[i], x), max(a[j], x+1));*/

    int ans; cin>>ans; return ans;
}

void solve()
{
    int n; cin>>n;

    set<int> cand;
    for (int i = 0; i<n; i+=2)
    {
        if (ask(1, i, (i+1)%n, n-1)>=n-1)
        {
            cand.insert(i); cand.insert((i+1)%n);
        }
    }

    int idx;

    for (auto it: cand)
    {
        if (ask(1, (it+1)%n, it, n-1)==n)
        {
            idx = it; break;
        }
    }

    vector<int> ans(n); ans[idx] = n;
    for (int i = 0; i<n; i++) if (i!=idx)
    {
        ans[i] = ask(2, i, idx, 1);
    }

    cout<<"! "; for (auto it: ans) cout<<it<<' ';
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}