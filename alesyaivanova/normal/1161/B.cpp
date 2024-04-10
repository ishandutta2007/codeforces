#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define pii pair<long long, long long>

const int MAXN = 200009;
int n, m;
int mod = 1000 * 1000 * 1000;

bool check(unordered_set<int>& s, int e)
{
    if (e == n)
        return false;
    for (int u : s)
    {
        int cur = (((u / mod + e) % n) * mod + (u % mod + e) % n);
        if (s.find(cur) == s.end())
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if ((b - a + n) % n <= n / 2)
            s.emplace(a * mod + b);
        if ((b - a + n) % n >= (n + 1) / 2)
            s.emplace(b * mod + a);
    }
    for (int e = 1; e * e <= n; e++)
    {
        if (n % e != 0)
            continue;
        if (check(s, e) || check(s, n / e))
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}