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


int p = 1000000007;


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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

int n;
vector<int> x, y;

set<ll> X, Y;

map<int, set<ll>> producerX(vector<int> cmp)
{
    map<int, set<ll>> mapka;
    for (auto it: cmp)
    {
         mapka[x[it]].insert(y[it]);
    }
    return mapka;
}

map<int, set<ll>> producerY(vector<int> cmp)
{
    map<int, set<ll>> mapka;
    for (auto it: cmp)
    {
        mapka[y[it]].insert(x[it]);
    }
    return mapka;
}



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
        return parent[v] = find_set(parent[v]);
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
       sz.resize(n);
       parent.resize(n);
       for (int i = 0; i<n; i++) make_set(i);
    }
};

bool check(ll t)
{

    DSU dsu(n);
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++)
        {
            bool connected = false;
            if (x[i]==x[j] && abs(y[i]-y[j])<=t) connected = true;
            if (y[i]==y[j] && abs(x[i]-x[j])<=t) connected = true;
            if (connected) dsu.union_sets(i, j);
        }

    set<int> roots;
    for (int i = 0; i<n; i++) roots.insert(dsu.find_set(i));
    int N = roots.size();
    if (N>4) return false;
    if (N==1) return true;

    map<int, int> mapka;
    int cur = -1;
    for (auto it: roots)
    {
        cur++; mapka[it] = cur;
    }



    vector<vector<int>> comps(N);
    for (int i = 0; i<n; i++) comps[mapka[dsu.find_set(i)]].push_back(i);

    if (N==2)
    {
        for (auto i: comps[0])
            for (auto j: comps[1])
            {
                if (x[i]==x[j] && abs(y[i]-y[j])/2<=t) return true;
                if (y[i]==y[j] && abs(x[i]-x[j])/2<=t) return true;
            }
    }

    vector<map<int, set<ll>>> mapX, mapY;
    for (auto it: comps)
    {
        mapX.push_back(producerX(it));
        mapY.push_back(producerY(it));
    }

    for (auto X1: X)
        for (auto Y1: Y)
        {
            bool connected = true;
            for (int i = 0; i<N; i++)
            {
                bool check = false;
                if (mapX[i].count(X1))
                {
                    auto it = mapX[i][X1].lower_bound(Y1 - t);
                    if (it!=mapX[i][X1].end() && abs((*it)-Y1)<=t) check = true;
                }
                if (mapY[i].count(Y1))
                {
                    auto it = mapY[i][Y1].lower_bound(X1 - t);
                    if (it!=mapY[i][Y1].end() && abs((*it)-X1)<=t) check = true;
                }
                if (!check)
                {
                    connected = false; break;
                }
            }
            if (connected) return true;
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;
    x.resize(n); y.resize(n);
    for (int i = 0; i<n; i++)
    {
        cin>>x[i]>>y[i];
        X.insert(x[i]); Y.insert(y[i]);
    }

    int L = 0;
    int R = 2e9;
    if (!check(R)) {cout<<-1<<endl; return 0;}
    while (R-L>1)
    {
        int mid = (R-L)/2 + L;
        if (check(mid)) R = mid;
        else L = mid;
    }
    cout<<R<<endl;
}