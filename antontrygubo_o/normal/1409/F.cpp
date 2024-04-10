#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


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

/*
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
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

const int INF = 1e9;

void solve()
{
    int n, k;
    cin>>n>>k;
    string s, t;
    cin>>s>>t;

    if (t[0]==t[1])
    {
        int cnt = 0;
        for (auto c: s) if (c==t[0]) cnt++;
        cnt = min(n, cnt + k);
        cout<<cnt*(cnt-1)/2; return;
    }

    vector<vector<int>> dp(k+1, vector<int>(n+1, -INF));
    dp[0][0] = 0;


    for (int sym = 0; sym<n; sym++)
    {
        vector<vector<int>> dp1(k+1, vector<int>(n+1, -INF));

        for (int ops = 0; ops<=k; ops++)
            for (int cur = 0; cur<=n; cur++)
            {
                //Option 1: Change to t[0]
                if (ops+1<=k) dp1[ops+1][cur] = max(dp1[ops+1][cur], dp[ops][cur] + cur);

                //Option 2: Change to s[0]

                if (ops+1<=k) dp1[ops+1][cur+1] = max(dp1[ops+1][cur+1], dp[ops][cur]);

                //Option 3: Don't change
                int cur1 = cur; int tot1 = dp[ops][cur];
                if (s[sym]==t[0]) cur1++;
                if (s[sym]==t[1]) tot1+=cur1;
                dp1[ops][cur1] = max(dp1[ops][cur1], tot1);
            }
        dp = dp1;
    }

    int best = 0;
    for (int ops = 0; ops<=k; ops++)
        for (int cur = 0; cur<=n; cur++)
        {
            best = max(best, dp[ops][cur]);
        }
    cout<<best;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}