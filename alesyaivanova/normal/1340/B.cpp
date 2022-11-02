#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

string kek_str[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int kek[10];
const int maxn = 2007;
bitset<maxn> dp[maxn];
int n, k;
int a[maxn];
vector<pii> cand[(1 << 7)];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10; i++)
        for (int e = 0; e < 7; e++)
            kek[i] = kek[i] * 2 + (kek_str[i][e] - '0');
    for (int mask = 0; mask < (1 << 7); mask++)
    {
        for (int i = 9; i >= 0; i--)
        {
            if ((mask & kek[i]) == mask)
            {
                int cur = (mask ^ kek[i]);
                int cnt = 0;
                for (int e = 0; e < 7; e++)
                {
                    if (cur & (1 << e))
                        cnt++;
                }
                cand[mask].pb(i, cnt);
            }
        }
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < 7; e++)
            a[i] = a[i] * 2 + (s[e] - '0');
    }
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (pii e : cand[a[i]])
            dp[i] |= (dp[i + 1] << e.ss);
    }
    if (!dp[0][k])
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (pii e : cand[a[i]])
        {
            if (e.ss <= k && dp[i + 1][k - e.ss])
            {
                cout << e.ff;
                k -= e.ss;
                break;
            }
        }
    }
}