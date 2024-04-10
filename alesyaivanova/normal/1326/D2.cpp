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

const int maxn = 2e6 + 9;
int f[maxn];

void solve(string& ans_str)
{
    string ss;
    cin >> ss;
    string s = "#";
    for (int i = 0; i < (int)ss.size(); i++)
    {
        s += ss[i];
        s += "#";
    }
    int n = s.size();
    int len = 0;
    while (len + 1 <= n / 2 && s[len] == s[n - len - 1])
        len++;
    if (s[len - 1] == '#')
        len--;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (i <= r)
            f[i] = min(f[l + r - i], r - i + 1);
        else
            f[i] = 0;
        while (i + f[i] < n && i - f[i] >= 0 && s[i + f[i]] == s[i - f[i]])
            f[i]++;
        if (i + f[i] - 1 > r)
        {
            r = i + f[i] - 1;
            l = i - f[i] + 1;
        }
    }
    int ans1 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (i - f[i] < len)
            ans1 = max(ans1, i + 1);
    }
    for (int i = n / 2; i < n; i++)
    {
        if (i + f[i] >= n - len)
            ans1 = max(ans1, n - i);
    }

    string s1 = "";
    for (int i = 0; i < n / 2; i++)
    {
        if (i - f[i] < len && ans1 == i + 1)
        {
            for (int e = 0; e <= i; e++)
                s1 += s[e];
            for (int e = i - 1; e >= 0; e--)
                s1 += s1[e];
            break;
        }
    }
    for (int i = n / 2; i < n; i++)
    {
        if (i + f[i] >= n - len && ans1 == n - i)
        {
            s1 = "";
            for (int e = n - 1; e >= i; e--)
                s1 += s[e];
            for (int e = (int)s1.size() - 2; e >= 0; e--)
                s1 += s1[e];
            break;
        }
    }
    ans_str = s1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        solve(s);
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] != '#')
                cout << s[i];
        }
        cout << "\n";
    }
}