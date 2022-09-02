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

/*
const int LIM = 200000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C1(int n, int k)
{
    return mul(invfacs[n], mul(facs[k], facs[n-k]));
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

int N = 0;

const int MAXX = 100000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> c(n), b(n-1);
    for (int i = 0; i<n; i++) cin>>c[i];
    for (int i = 0; i<n-1; i++) cin>>b[i];

    for (auto it: c) N+=it;

    //a_i -= (b_0 + ... + b_(i-1))
    //Need:

    vector<int> prefs(n);
    for (int i = 1; i<n; i++) prefs[i] = prefs[i-1] + b[i-1];

    vector<int> lim(n);
    int cursum = 0;
    for (int i = 0; i<n; i++)
    {
        cursum+=prefs[i]; lim[i] = cursum;// + (i+1)*x;
    }

    map<int, int> mapka;

    vector<vector<int>> possible(n+1, vector<int>(N+1));
    possible[0][0] = 1;
    for (int i = 1; i<=n; i++)
    {
        for (int prv = 0; prv<=N; prv++)
            for (int ch = 0; ch<=c[i-1]; ch++) if (prv+ch<=N) possible[i][prv+ch] = add(possible[i][prv+ch], possible[i-1][prv]);
    }

    vector<int> pref_c(n);
    pref_c[0] = c[0];
    for (int i = 1; i<n; i++) pref_c[i] = pref_c[i-1] + c[i];

    int TOT = 0;
    for (auto it: possible[n]) TOT = add(TOT, it);

    for (int x = -MAXX; x<=MAXX; x++)
    {
        //For every i from 0 to n-1 check the condition
        bool lose = false;
        int starter = n+1;
        for (int i = 0; i<n; i++)
        {
            if (lim[i]+(i+1)*x>pref_c[i]) {lose = true; break;}
            if (lim[i]+(i+1)*x>0) starter = min(starter, i);
        }

        if (lose)
        {
            mapka[x] = 0;
            continue;
        }

        if (starter == n+1)
        {
            mapka[x] = TOT;
            continue;
        }

        //starter is the first point where we are not sure

        vector<int> dp(possible[starter].begin(), possible[starter].end());

        //Need to write transition function now

        vector<int> true_lim(n);
        for (int i = 0; i<n; i++) true_lim[i] = lim[i] + (i+1)*x;

        for (int i = starter; i<=n-1; i++)
        {
            vector<int> pref_dp(N+2);
            for (int j = 1; j<=N+1; j++) pref_dp[j] = add(pref_dp[j-1], dp[j-1]);

            for (int cur = 0; cur<true_lim[i]; cur++) dp[cur] = 0;

            for (int cur = max(true_lim[i], 0); cur<=N; cur++)
            {
                //We need to sum on [cur-c[i], cur]
                int l = max(0, cur-c[i]); int r = cur;
                if (i>0)
                {
                    l = max(l, true_lim[i-1]);
                    r = max(r, true_lim[i-1]);
                }
                dp[cur] = sub(pref_dp[r+1], pref_dp[l]);
            }
        }

        int ans = 0; for (auto it: dp) ans = add(ans, it);
        mapka[x] = ans;

    }

    /*vector<int> dp(N);
    dp[0] = 1;
    for (int i = 0; i<n; i++)
    {
        vector<int> dp1(N);
        int kek = 0; if (i>0) kek = max(0, lim[i-1]);
        for (int prv = kek; prv<N; prv++)
        {
            for (int ch = 0; ch<=c[i]; ch++) if (prv+ch>=lim[i] && prv+ch<N) dp1[prv+ch] = add(dp1[prv+ch], dp[prv]);
        }
        dp = dp1;


    }

    int ans = 0;
    for (auto it: dp) ans = add(ans, it);
    cout<<ans<<endl;*/


    int q; cin>>q;
    while (q--)
    {
        int x; cin>>x; cout<<mapka[x]<<endl;

    }

}
/*
100
1
0
 */