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
const int LIM = 1000;

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

int solve1(vector<ll> a, ll diff)
{
    /*
     * This shit looks like CCCCPCPCPCPPPPPP
     */
    int n = a.size();

    if (n<4) return 0;

    vector<ll> a1;
    for (int i = 2; i<n-2; i++) a1.push_back(a[i]);

    diff-=a[n-1]; diff-=a[n-2];
    diff+=a[0]; diff+=a[1];

    a = a1; n-=4;
    //Now we want sum of Ps - sum of Cs>diff

    vector<ll> odd, even;

    ll sum_odd = 0; ll sum_even = 0;

    for (int i = 0; i<n; i++)
    {
        if (i%2) sum_odd-=a[i];
        else sum_even-=a[i];
    }

    odd.push_back(sum_odd); even.push_back(sum_even);
    for (int i = n-1; i>=0; i--)
    {
        if (i%2)
        {
            sum_odd+=2*a[i]; odd.push_back(sum_odd);
        }
        else
        {
            sum_even+=2*a[i]; even.push_back(sum_even);
        }
    }

    //Now we need to count for how many pairs sum is > diff

    int K = odd.size();
    int cur = K-1;

    int ans = 0;

    for (auto it: even)
    {
        while (cur>=0 && odd[cur]+it>diff) cur--;
        ans = add(ans, K-cur-1);
    }
    return ans;

}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); for (int i = 0; i<n; i++) cin>>a[i];

    int cnt = 0;

    /*
     No PP, no CC
     */

    ll odd = 0; ll even = 0;
    for (int i = 0; i<n; i++)
    {
        if (i%2) odd+=a[i]; else even+=a[i];
    }

    if (odd!=even) cnt++;



    //cout<<cnt<<endl;






    /*
     Only CC
     */

    vector<ll> alternating(n+1);
    for (int i = n-1; i>=0; i--) alternating[i] = a[i] - alternating[i+1];

    //Start with C:
    ll cur = 0;
    for (int i = 0; i<n; i++)
    {
        cur+=a[i];
        if (i>=1)
        {
            ll diff = cur - alternating[i+1];
            if (diff<0) cnt = add(cnt, 1);
        }
    }

    //Start with P
    cur = -a[0];
    for (int i = 1; i<n; i++)
    {
        cur+=a[i];
        if (i>=2)
        {
            ll diff = cur-alternating[i+1];
            if (diff<0) cnt = add(cnt, 1);
        }
    }



    //cout<<cnt<<endl;






    /*
     Only PP
     */

    alternating[0] = 0;
    for (int i = 1; i<=n; i++) alternating[i] = a[i-1] - alternating[i-1];

    //Start with P
    cur = 0;
    for (int i = n-1; i>=0; i--)
    {
        cur+=a[i];
        if (i<=n-2)
        {
            ll diff = cur-alternating[i];
            if (diff>0) cnt = add(cnt, 1);
        }
    }

    //Start with C
    cur = -a[n-1];
    for (int i = n-2; i>=0; i--)
    {
        cur+=a[i];
        if (i<=n-3)
        {
            ll diff = cur-alternating[i];
            if (diff>0) cnt = add(cnt, 1);
        }
    }





    //cout<<cnt<<endl;





    /*
     * Now we have blocks of both PP and CC
     */

    //First block of PP, then block of CC

    cur = 0;
    for (auto it: a) cur+=it;
    for (int i = n-1; i>=0; i--)
    {
        cur-=a[i]; cur-=a[i];
        if (i<=n-2 && i>=2)
        {
            if (cur>0) cnt = add(cnt, 1);
        }
    }





    //cout<<cnt<<endl;






    //First block of CC, then block of PP: the real killer of this shit

    //Consider cases:

    //Start with C end with P
    cnt = add(cnt, solve1(a, 0));

    //Start with P end with P
    vector<ll> guys; for (int i = 1; i<n; i++) guys.push_back(a[i]);
    cnt = add(cnt, solve1(guys, -a[0]));

    //Start with C end with C
    guys.clear(); for (int i = 0; i<n-1; i++) guys.push_back(a[i]);
    cnt = add(cnt, solve1(guys, a[n-1]));

    //Start with P end with C
    guys.clear(); for (int i = 1; i<n-1; i++) guys.push_back(a[i]);
    cnt = add(cnt, solve1(guys, a[n-1]-a[0]));

    cout<<cnt<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();



}

/*
1
5
2 1 2 1 1
 */