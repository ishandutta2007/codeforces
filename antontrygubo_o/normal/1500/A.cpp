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

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    /*int t; cin>>t;
    while (t--) solve();*/

    int n; cin>>n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first; a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    map<int, int> mapka;

    //for (auto it: a) cout<<it.first<<' '<<it.second<<endl;

    for (int i = 1; i<n; i+=2)
    {
        if (mapka.find(a[i].first - a[i-1].first)!=mapka.end())
        {
            int j = mapka[a[i].first - a[i-1].first];
            cout<<"YES"<<endl;
            cout<<a[i].second<<' '<<a[j-1].second<<' '<<a[i-1].second<<' '<<a[j].second<<endl; return 0;
        }
        mapka[a[i].first - a[i-1].first] = i;
    }

    //cout<<"HERE"<<endl;

    vector<vector<pair<int, int>>> cnt(2500000);
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++)
        {
            cnt[a[j].first - a[i].first].push_back(mp(i, j));
        }

    for (auto vec: cnt)
    {
        int k = vec.size();
        for (int i = 1; i<k; i++)
        {
            for (int j = 0; j<i; j++)
            {
                if (vec[i].first!=vec[j].first && vec[i].first!=vec[j].second && vec[i].second!=vec[j].first && vec[i].second!=vec[j].second)
                {
                    cout<<"YES"<<endl;
                    cout<<a[vec[i].first].second<<' '<<a[vec[j].second].second<<' '<<a[vec[i].second].second<<' '<<a[vec[j].first].second<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"NO";



}
/*

 */

/*
1 + 2 + ... + n <= 5*10^6
n<=1000 or smth
 */