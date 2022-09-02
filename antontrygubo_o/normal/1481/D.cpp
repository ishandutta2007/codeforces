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

int p =  998244353;

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


mt19937 rnd(time(0));

/*
const int N = 1e6 + 5;

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

/*
struct DSU
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
   int n, m;
   cin>>n>>m;

   vector<string> s(n); for (int i = 0; i<n; i++) cin>>s[i];
   for (int i = 0; i<n; i++)
       for (int j = i+1; j<n; j++) if (s[i][j] == s[j][i] || m%2)
       {
           cout<<"YES"<<endl;
           for (int k = 0; k<=m; k++)
           {
               if (k%2) cout<<i+1<<' '; else cout<<j+1<<' ';
           }
           cout<<endl; return;
       }


   //cout<<"NOT DONE YET!!!!"<<endl;
   for (int i = 0; i<n; i++)
   {
       int A = -1; int B = -1;
       for (int j = 0; j<n; j++)
       {
           if (s[i][j]=='a') A = j; if (s[i][j]=='b') B = j;
       }
       if (A==-1 || B==-1) continue;
       cout<<"YES"<<endl;
       vector<int> ops;
       for (int j = 0; j<=m/2; j++)
       {
           if (j%2) ops.push_back(A); else ops.push_back(i);
       }
       reverse(ops.begin(), ops.end());

       /*for (auto it: ops) cout<<it+1<<' ';
       cout<<endl;*/

       for (int j = 0; j<m/2; j++)
       {
           if (j%2) ops.push_back(i); else ops.push_back(B);
       }
       for (auto it: ops) cout<<it+1<<' ';
       cout<<endl; return;
   }

   cout<<"NO"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();

}
/*
1
3 4
*aa
b*a
bb*
 */