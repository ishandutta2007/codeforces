#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1000 * 1000 * 1000 + 7;
int dp[10009][100];

pair<int, int> add(pair<int, int> a, pair<int, int> b)
{
    a.first = (a.first * b.second) % mod;
    b.first = (b.first * a.second) % mod;
    return make_pair((a.first + b.first) % mod, (a.second * b.second) % mod);
}

int fast_pow(int a, int p)
{
    if (p == 1)
        return a;
    int b = fast_pow(a, p / 2);
    b = (b * b) % mod;
    if (p % 2 == 1)
        b = (b * a) % mod;
    return b;
}

int divm(int a, int b)
{
    return (fast_pow(b, mod - 2) * a) % mod;
}

int find_ans(int d, int k, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        //dp[1][i].first = 1;
        //dp[1][i].second = cnt;
        dp[1][i] = divm(1, cnt);
    }
    for (int t = 2; t <= k; t++)
    {
        int cur = 0;
        for (int i = 0; i < cnt; i++)
        {
            int q = dp[t - 1][i];
            q = divm(q, cnt - i);
            //q.second *= cnt - i;
            //q.second %= mod;
            cur = (cur + q) % mod;
            //cout << cur.first << " " << cur.second << "\n";
            dp[t][i] = cur;
        }
    }
    int ans = 0;
    int u = 1;
    for (int i = cnt - 1; i >= 0; i--)
    {
        int q = dp[k][i];
        q = (q * u) % mod;
        //q.first *= u;
        //q.first %= mod;
        ans = (ans + q) % mod;
        u = (u * d) % mod;
    }
    return ans;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, k;
    cin >> a >> k;
    int ans = 1;
    for (int i = 2; i * i <= a || (a > 1); i++)
    {
        if (i * i > a)
            i = a;
        if (a % i != 0)
            continue;
        int cnt = 0;
        while (a % i == 0)
        {
            a /= i;
            cnt++;
        }
        int cur = find_ans(i, k, cnt + 1);
        //cout << cur.first << " " << cur.second << "\n";
        ans = (ans * cur) % mod;
    }
    cout << ans;
}