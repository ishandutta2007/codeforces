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

/*
const int LIM = 100000;

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

/*
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

int n, k;

int LEN;

int xor1(int a, int b)
{
    return (a+b)%k;
}

vector<int> to_k(int x)
{
    vector<int> ans;
    for (int i = 0; i<LEN; i++)
    {
        ans.push_back(x%k);
        x/=k;
    }
    return ans;
}

int to_10(vector<int> a)
{
    reverse(a.begin(), a.end());
    int res = 0;
    for (auto it: a) res = res*k+it;
    return res;
}

int XOR1(int a, int b)
{
    auto vec1 = to_k(a); auto vec2 = to_k(b);
    for (int i = 0; i<LEN; i++) vec1[i] = xor1(vec1[i], vec2[i]);
    return to_10(vec1);
}

int negat(int a)
{
    auto vec = to_k(a);
    for (int i = 0; i<LEN; i++) vec[i] = (k-vec[i])%k;
    return to_10(vec);
}

void solve()
{
    cin>>n>>k;

    int xoring = 0;

    int basing = 1;
    LEN = 0;
    while (basing<n)
    {
        LEN++; basing*=k;
    }

    bool neg = false;

    for (int i = 0; i<n; i++)
    {

        if (!neg)
        {

            //Means password is ans+xoring

            cout<<XOR1(i, xoring)<<endl;
            int r; cin>>r;
            if (r==1) return;

                //password was ans+xoring, becomes (i+xoring) - (ans+xoring) = (i-ans)

            neg = true; xoring = i;
        }
        else
        {
            //Means password is (-ans)+xoring

            cout<<XOR1(negat(i), xoring)<<endl;
            int r; cin>>r;
            if (r==1) return;

            //password was (-ans)+xoring, becomes (-i+xoring) - (-ans+xoring) = ans-i

            neg = false; xoring = negat(i);
        }


    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();

}
/*

 
1
5 2

Password is 2 
 
//password becomes 2
0 //password becomes 3
1 //password is guessed


 */