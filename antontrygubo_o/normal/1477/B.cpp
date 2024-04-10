#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair
/*
int p =  1e9 + 7;

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

int po(int a, ll deg)
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
*/

mt19937 rnd(time(0));

/*
const int N = 2000005;

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


/*struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> cycle;
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
        if (a==b) cycle[a] = true;
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (cycle[b]) cycle[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        cycle.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

void solve()
{
    int n, q;
    cin>>n>>q;

    string s, f;
    cin>>s>>f;
    vector<pair<int, int>> a(q);
    for (int i = 0; i<q; i++)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--; a[i].second--;
    }

    set<pair<pair<int, int>, int>> bits;
    for (int i = 0; i<n; i++)
    {
        if (f[i]=='0') bits.insert(mp(mp(i, i), 0));
        else bits.insert(mp(mp(i, i), 1));
    }

    //for (auto it: bits) cout<<it.first.first<<' '<<it.first.second<<' '<<it.second<<endl;

    reverse(a.begin(), a.end());
    for (auto query: a)
    {
        int l = query.first; int r = query.second;
        int cnt = 0;
        auto it = *prev(bits.lower_bound(mp(mp(l+1, -1), -1)));
        if (it.first.first!=l)
        {
            bits.erase(it);
            bits.insert(mp(mp(it.first.first, l-1), it.second));
            bits.insert(mp(mp(l, it.first.second), it.second));
        }

        it = *prev(bits.lower_bound(mp(mp(r+1, -1), -1)));
        if (it.first.second!=r)
        {
            bits.erase(it);
            bits.insert(mp(mp(it.first.first, r), it.second));
            bits.insert(mp(mp(r+1, it.first.second), it.second));
        }

        while (bits.lower_bound(mp(mp(l, -1), -1))!=bits.end())
        {
            auto it = *bits.lower_bound(mp(mp(l, -1), -1));
            if (it.first.first>r) break;
            cnt+=(it.second)*(it.first.second-it.first.first + 1);
            bits.erase(it);
        }

        if (2*cnt<r-l+1) bits.insert(mp(mp(l, r), 0));
        else if (2*cnt>r-l+1) bits.insert(mp(mp(l, r), 1));
        else {cout<<"NO"<<endl; return;}

        /*cout<<"AFTER QUERY "<<l<<' '<<r<<endl;
        for (auto it: bits) cout<<it.first.first<<' '<<it.first.second<<' '<<it.second<<endl;*/

    }

    vector<int> b(n);
    for (auto it: bits)
    {
        for (int i = it.first.first; i<=it.first.second; i++) b[i] = it.second;
    }

    for (int i = 0; i<n; i++) if (b[i]!=(s[i]-'0')) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;

}

/*
1
10 6
1111111111
0110001110
1 10
5 9
7 10
1 7
3 5
6 10

 */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();
}