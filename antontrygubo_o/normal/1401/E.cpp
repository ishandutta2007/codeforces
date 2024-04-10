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
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

const int MAXX = (1<<21);

vector<ll> t(MAXX);

int N = 1e6;

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<pair<int, pair<int, int>>> hor;

    vector<vector<int>> st(N+1), en(N+1);
    for (int i = 0; i<n; i++)
    {
        int y, l, r;
        cin>>y>>l>>r;
        st[l].push_back(y); en[r].push_back(y);
    }
    st[0].push_back(0); en[N].push_back(0);
    st[0].push_back(N); en[N].push_back(N);

    /*for (int i = 0; i<=N; i++) if (st[i].size() || en[i].size())
    {
        cout<<i<<":"<<endl;
        cout<<"Opening: ";
        for (auto it: st[i]) cout<<it<<' ';
        cout<<endl;
        cout<<"Closing: ";
        for (auto it: en[i]) cout<<it<<' ';
        cout<<endl;
    }*/



    vector<pair<int, int>> ver(N+1);
    for (int i = 0; i<=N; i++) ver[i] = mp(-1, -1);

    for (int i = 0; i<m; i++)
    {
        int x, l, r;
        cin>>x>>l>>r;
        ver[x] = mp(l, r);
    }

    ver[0] = mp(0, N);
    ver[N] = mp(0, N);

    ll res = 0;

    for (int i = 0; i<=N; i++)
    {
        for (auto it: st[i])
        {
            update(1, 0, N, it, 1);
        }
        if (ver[i].first!=-1)
        {
            //cout<<i<<": "<<ver[i].first<<' '<<ver[i].second<<endl;
            res+=sum(1, 0, N, ver[i].first, ver[i].second);
        }
        //cout<<res<<endl;
        for (auto it: en[i]) update(1, 0, N, it, -1);
    }
    cout<<res - m - n - 3;

}