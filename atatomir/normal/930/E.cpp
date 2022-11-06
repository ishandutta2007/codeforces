#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 400011
#define mod 1000000007
#define inf 1000000005

int k, n, m, i;
vector< pair<int, int> > t1, t2;
vector<int> ord;

int rest1[maxN], rest2[maxN];
ll dp[maxN][4], sol[maxN], sum_sol[maxN];
ll sum1[maxN], sum2[maxN], sum3[maxN];

pair<ll, ll> last1, last2;

void clean(vector< pair<int, int> >& data) {
    int i, low;
    vector< pair<int, int> > ans = {};

    sort(data.begin(), data.end(), [](const pair<int, int> & a, const pair<int, int> & b)->bool const {
        return mp(-a.first, a.second) < mp(-b.first, b.second);
    });

    low = inf;
    for (auto e : data) {
        if (e.second >= low) continue;
        low = e.second;
        ans.pb(e);
    }

    data = ans;
}

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> k >> n >> m;
    t1.resize(n);
    t2.resize(m);
    for (auto& e : t1) cin >> e.first >> e.second;
    for (auto& e : t2) cin >> e.first >> e.second;

    clean(t1);
    clean(t2);

    for (auto e : t1) {
        ord.pb(e.first - 1);
        ord.pb(e.second);
    }

    for (auto e : t2) {
        ord.pb(e.first - 1);
        ord.pb(e.second);
    }

    ord.pb(k);
    ord.pb(0);
    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());

    for (auto e : t1) {
        int p1 = lower_bound(ord.begin(), ord.end(), e.first - 1) - ord.begin() + 2;
        int p2 = lower_bound(ord.begin(), ord.end(), e.second) - ord.begin() + 1;

        rest1[p2] = p1;
    }

    for (auto e : t2) {
        int p1 = lower_bound(ord.begin(), ord.end(), e.first - 1) - ord.begin() + 2;
        int p2 = lower_bound(ord.begin(), ord.end(), e.second) - ord.begin() + 1;

        rest2[p2] = p1;
    }

    dp[1][2] = sol[1] = sum_sol[1] = 1;
    sum3[1] = 1;

    n = ord.size();
    for (i = 2; i <= n; i++) {
        //! put a 3 here
        ll pow2 = poww(2, ord[i - 1] - ord[i - 2]) + mod - 2;
        dp[i][3] = (sol[i - 1] * pow2) % mod;

        if (rest1[i] != 0) last1 = mp(rest1[i], i);
        if (rest2[i] != 0) last2 = mp(rest2[i], i);

        //! put a 1
        ll limit = max(1LL, last2.first);
        dp[i][1] = (sum_sol[i - 1] - sum_sol[limit - 1]) - (sum1[i - 1] - sum1[limit - 1]);
        dp[i][1] = (dp[i][1] + 2 * mod) % mod;

        //! put a 2
        limit = max(1LL, last1.first);
        dp[i][2] = (sum_sol[i - 1] - sum_sol[limit - 1]) - (sum2[i - 1] - sum2[limit - 1]);
        dp[i][2] = (dp[i][2] + 2 * mod) % mod;

        sol[i] = (dp[i][1] + dp[i][2] + dp[i][3]) % mod;
        sum_sol[i] = (sum_sol[i - 1] + sol[i]) % mod;

        sum1[i] = (sum1[i - 1] + dp[i][1]) % mod;
        sum2[i] = (sum2[i - 1] + dp[i][2]) % mod;
        sum3[i] = (sum3[i - 1] + dp[i][3]) % mod;
    }

    cout << sol[n];

    return 0;
}