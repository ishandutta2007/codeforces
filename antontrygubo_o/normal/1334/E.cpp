#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 998244353;


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

/*struct DSU {
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}


void solve()
{

    ll d;
    cin>>d;
    vector<ll> pr;
    for (ll i = 2; i*i<=d; i++) if (d%i==0)
    {
        pr.push_back(i);
        while (d%i==0) d/=i;
    }
    if (d!=1) pr.push_back(d);


    int q;
    cin>>q;
    for (int i = 0; i<q; i++)
    {
        ll u, v;
        cin>>u>>v;
        vector<int> a, b;
        for (auto it: pr)
        {
            int cnt = 0;
            while (u%it==0)
            {
                cnt++; u/=it;
            }
            a.push_back(cnt);
        }
        for (auto it: pr)
        {
            int cnt = 0;
            while (v%it==0)
            {
                cnt++; v/=it;
            }
            b.push_back(cnt);
        }

        int k = a.size();

        vector<int> down;
        for (int i = 0; i<k; i++) down.push_back(a[i] - min(a[i], b[i]));
        vector<int> up;
        for (int i = 0; i<k; i++) up.push_back(b[i] - min(a[i], b[i]));

        int totdown = 0;
        for (int i = 0; i<k; i++) totdown+=down[i];
        totdown = facs[totdown];
        for (auto it: down) totdown = mul(totdown, invfacs[it]);

        int totup = 0;
        for (int i = 0; i<k; i++) totup+=up[i];
        totup = facs[totup];
        for (auto it: up) totup = mul(totup, invfacs[it]);
        cout<<mul(totdown, totup)<<endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    solve();
}