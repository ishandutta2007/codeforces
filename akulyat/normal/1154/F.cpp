#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, m, k;
vector<ll> pr;
unordered_map<ll, ll> best;
vector<vector<ll>> sum;
vector<ll> dp;
bool viv = false;

void precalc() {
    sum.resize(k);
    for (auto& l : sum)
        l.resize(k);
    for (ll i = 0; i < k; i++)
        sum[i][i] = pr[i];
    for (ll i = 0; i < k; i++)
        for (ll j = i + 1; j < k; j++)
            sum[i][j] = sum[i][j - 1] + pr[j];
}

void solve(ll dig) {
    for (ll i = 1; i <= dig; i++) {
        ll was = dp[dig - i];
        ll will = sum[dig - i][dig - 1];
        if (best.find(i) != best.end())
            will -= sum[dig - i][dig - i + best[i] - 1];
      //  cout << dig << ' ' << i << ' ' << was << ' ' << will << endl;
        dp[dig] = min(dp[dig], was + will);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pr.push_back(a);
    }
    sort(pr.begin(), pr.end());
    while (pr.size() > k)
        pr.pop_back();
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if (best.find(a) == best.end())
            best[a] = b;
        else
            best[a] = max(best[a], b);
    }
    dp.resize(n + 1);
    for (ll i = 0; i < k; i++)
        dp[i + 1] = dp[i] + pr[i];
    precalc();

    for (ll i = 1; i <= k; i++)
        solve(i);
    cout << dp[k];

    return 0;
}