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

/*const int N = 1200000;

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
}*/


void solve()
{
    ll n, l, r;
    cin>>n>>l>>r;
    ll len = 0;
    int cur = 1;
    while (cur<n-1 && len + 2*(n -cur)<l)
    {
        len+=2*(n-cur); cur++;
    }

    //cout<<len<<' '<<cur<<endl;

    vector<int> guys;
    while (cur<n)
    {
        for (int i = cur+1; i<=n; i++)
        {
            guys.push_back(cur);
            guys.push_back(i);
        }
        if (guys.size()>=r-len) break;
        cur++;
    }
    if (guys.size()<r-len)
    {
        guys.push_back(1);
    }


    /*cout<<cur<<' '<<len<<endl;
    for (auto it: guys) cout<<it<<' ';
    cout<<endl;*/

    for (ll i = l; i<=r; i++) cout<<guys[i-len-1]<<' ';
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--)  solve();
}

/*
1
99995 9998900031 9998900031
 */