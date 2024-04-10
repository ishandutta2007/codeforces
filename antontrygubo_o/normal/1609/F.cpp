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

int MOD =  998244353;

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

const int N = 1'000'000;


vector<vector<pair<int, int>>> cnt_max(60), cnt_min(60);

int n;
vector<ll> a;

ll ans = 0;

vector<int> maxs = {-1};
vector<int> mins = {-1};

int cntbit(ll n)
{
    int res = 0;
    while (n)
    {
        res+=(n%2);
        n/=2;
    }
    return res;
}

int sum_max(int pos, int color)
{
    pos = min(pos, maxs.back());

    if (pos==-1) return 0;

    int k1 = prev(lower_bound(cnt_max[color].begin(), cnt_max[color].end(), mp(pos, -1))) - cnt_max[color].begin();
    int k = lower_bound(maxs.begin(), maxs.end(), pos) - maxs.begin();

    int res = cnt_max[color][k1].second;
    if (color == cntbit(a[maxs[k]])) res+=(pos - maxs[k-1]);
    return res;
}

int sum_min(int pos, int color)
{
    pos = min(pos, mins.back());

    if (pos==-1) return 0;

    int k1 = prev(lower_bound(cnt_min[color].begin(), cnt_min[color].end(), mp(pos, -1))) - cnt_min[color].begin();
    int k = lower_bound(mins.begin(), mins.end(), pos) - mins.begin();

    /*if (pos==2 && color==2)
    {
        cout<<"Mistake: "<<k<<' '<<k1<<endl;
    }*/

    int res = cnt_min[color][k1].second;
    if (color == cntbit(a[mins[k]])) res+=(pos - mins[k-1]);

    return res;
}

void print(vector<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void pop_max()
{
    int sz1 = maxs.size();
    int l = maxs[sz1-2];
    int r = maxs[sz1-1];

    int color = cntbit(a[maxs[sz1-1]]);
    maxs.pop_back();
    cnt_max[color].pop_back();

    /*if (l==-1 && r==2)
    {
        cout<<"Here: "<<sum_min(r, color)<<' '<<sum_min(l, color)<<endl;
    }*/

    ans-=(sum_min(r, color) - sum_min(l, color));

    //cout<<"After popping max: "<<endl; print(mins); print(maxs); cout<<ans<<endl;

}

void pop_min()
{
    int sz1 = mins.size();
    int l = mins[sz1-2];
    int r = mins[sz1-1];

    int color = cntbit(a[mins[sz1-1]]);
    mins.pop_back();
    cnt_min[color].pop_back();

    ans-=(sum_max(r, color) - sum_max(l, color));

    //cout<<"After popping min: "<<endl; print(mins); print(maxs); cout<<ans<<endl;
}

void push_max(int pos)
{
    int sz1 = maxs.size();
    int l = maxs[sz1-1];
    int r = pos;

    int color = cntbit(a[pos]);
    ans+=(sum_min(r, color) - sum_min(l, color));
    maxs.push_back(pos);

    auto pr = cnt_max[color].back();

    cnt_max[color].push_back(mp(pos, pr.second + (r-l)));
    //cout<<"After pushing max: "<<endl; print(mins); print(maxs); cout<<ans<<endl;
}

void push_min(int pos)
{
    int sz1 = mins.size();
    int l = mins[sz1-1];
    int r = pos;

    int color = cntbit(a[pos]);
    ans+=(sum_max(r, color) - sum_max(l, color));
    mins.push_back(pos);

    auto pr = cnt_min[color].back();

    cnt_min[color].push_back(mp(pos, pr.second + (r-l)));
    //cout<<"After pushing min: "<<endl; print(mins); print(maxs); cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 0; i<60; i++)
    {
        cnt_min[i].push_back(mp(-1, 0));
        cnt_max[i].push_back(mp(-1, 0));
    }

    cin>>n;
    a.resize(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    ll tot = 0;

    for (int i = 0; i<n; i++)
    {
        //cout<<endl<<"Processing "<<i<<": "<<endl;

        while (maxs.back()!=-1 && a[maxs.back()]<=a[i]) pop_max();
        while (mins.back()!=-1 && a[mins.back()]>=a[i]) pop_min();

        push_max(i);
        push_min(i);

        //cout<<ans<<endl;

        tot+=ans;
    }

    cout<<tot<<endl;



}

/*
4
1 2 3 4
 */