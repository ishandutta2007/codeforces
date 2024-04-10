#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;



#define mp make_pair

const int p =  1e9 + 7;

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
}




/*struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> activated;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void activate(int a)
    {
        activated[find_set(a)] = true;
    }

    bool is_activated(int a)
    {
        return activated[find_set(a)];
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (activated[b]) activated[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        activated.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

int n, k;

int ask(int q)
{
    cout<<"? "<<(q-1)%n + 1<<endl;
    int ans; cin>>ans; return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>k;
    for (int i = 0; i<400; i++) ask(1);
    int step = min(350, n/4);

    int cur = 1;
    int val = ask(1);
    int cur1, val1;
    while (true)
    {
        cur1 = cur + step;
        val1 = ask(cur1);
        if (val<val1) break;
        else {cur = cur1; val = val1;}
    }

    while (cur1-cur>1)
    {
        int mid = (cur+cur1)/2;
        if (ask(mid)<ask(cur1)) cur = mid; else cur1 = mid;
    }

    int ans;
    if (ask(cur1)<ask(cur1+1)) ans = cur1; else ans = cur;
    cout<<"! "<<(ans-1)%n + 1<<endl;



    /*int n = 19; int k = 10;
    vector<int> a(n, k);
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
    for (int iter = 0; iter<100; iter++)
    {
        vector<int> b(n);
        for (int i = 0; i<n-1; i++)
        {
            b[(i+n-1)%n]+=a[i]/2;
            b[(i+1)%n]+=(a[i] - a[i]/2);
        }
        b[0]+=a[n-1];
        a = b;
        for (auto it: a) cout<<it<<' ';
        cout<<endl;
    }*/



}