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



void solve() {

    int n; cin>>n;

    int mid = (n+1)/2;

    vector<int> p;
    p.push_back(1);
    for (int i = mid+1; i<=n; i++) p.push_back(i);
    for (int i = mid; i>=2; i--) p.push_back(i);
    /*for (auto it: p) cout<<it<<' ';
    cout<<endl;*/


    vector<int> a(n+1);
    //for (int i = 0; i<n; i++)
    //p[1] stands at p[2] -> swap(p[1], p[2],

    //p[1] - ? p[2] - p[1]
    //p[1] - p[1], p[2] - ?
    for (int i = 0; i<n; i++) a[p[i]] = p[(i+1)%n];
    vector<int> b(a);
    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;*/
    ll ans = 0;
    vector<pair<int, int>> ops;
    for (int i = 1; mid+i<n; i++)
    {
        ops.push_back(mp(1, mid+i));
        swap(a[1], a[mid+i]);
        ans+=1ll*(mid+i-1)*(mid+i-1);
    }

   /* for (auto it: a) cout<<it<<' ';
    cout<<endl;*/

    for (int i = mid; i>=1; i--)
    {
        ops.push_back(mp(n, i));
        swap(a[n], a[i]);
        ans+=1ll*(n-i)*(n-i);
    }

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;*/

    cout<<ans<<endl;
    for (int i = 1; i<=n; i++) cout<<b[i]<<' ';
    cout<<endl;
    cout<<ops.size()<<endl;
    for (auto it: ops) cout<<it.second<<' '<<it.first<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();
}



/*
1
10
 */