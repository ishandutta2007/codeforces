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


const int MOD =  1e9 + 7;

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


/*const int LIM = 1e6 + 5;

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


/*
With 3 numbers????
n%2=0

x, y, z; n/3<=x<=n/2 -> x = LCM
x divisible by y and z
y>=n/4
So x = y or x = 2y
x = y, z means z even -> x, y even but

2x, x, x

x divisible by 4 -> 2x, x, x
x = 4k+2 -> 2k, 2k, 2



Then can cover range from (k-2) to 2*(k-2)
k = 3? ->

Cover from 2 to 4
4x+1 -> 2x, x, x, 1
4x+2 -> 2x, x, x, 2
4x+3 -> 2x, 2x, 2, 1
4x -> x, x, x, x
 */

void solve()
{
    int n, k; cin>>n>>k;

    if (n-k+1<=n/2)
    {
        for (int i = 0; i<k-1; i++) cout<<1<<' ';
        cout<<n-(k-1)<<endl;
        return;
    }

    if (n%2 == k%2)
    {
        int mid = (n-(k-2))/2;
        cout<<mid<<' '<<mid<<' ';
        for (int i = 0; i<k-2; i++) cout<<1<<' ';
        cout<<endl; return;
    }

    if (k==3)
    {
        if (n%4==0)
        {
            cout<<n/2<<' '<<n/4<<' '<<n/4<<endl; return;
        }
        cout<<(n-2)/2<<' '<<(n-2)/2<<' '<<2<<endl; return;
    }
    if (k==4)
    {
        if (n%4==1)
        {
            cout<<n/2<<' '<<n/4<<' '<<n/4<<' '<<1<<endl; return;
        }
        int x = (n-3)/4;
        cout<<2*x<<' '<<2*x<<' '<<2<<' '<<1<<endl; return;
    }

    //Now they can make any number from (k-2) to 2*(k-2)

    int good = (k-2);
    while (good%4 != n%4) good++;
    cout<<(n-good)/2<<' '<<(n-good)/2<<' ';
    for (int i = 0; i<k-2; i++)
    {
        if (i<good - (k-2)) cout<<2<<' '; else cout<<1<<' ';
    }
    cout<<endl;





}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();
}