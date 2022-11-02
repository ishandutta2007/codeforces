#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 5009;
int dp[MAX_N];
int n, a1, b1;
int inf = 1000 * 1000 * 1000;
int suf[MAX_N];
int pos[MAX_N];
pair<pair<int, int>, int> a[MAX_N];
int num[MAX_N];
int new_num[MAX_N];
int head[MAX_N];
int lcp[MAX_N];

void build_suf(string& s)
{
    for (int i = 0; i < n; i++)
        head[s[i] - 'a' + 1]++;
    for (int i = 1; i < MAX_N; i++)
        head[i] += head[i - 1];
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        suf[head[c]] = i;
        head[c]++;
    }
    num[suf[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        num[suf[i]] = num[suf[i - 1]];
        if (s[suf[i - 1]] != s[suf[i]])
            num[suf[i]]++;
    }
    for (int len = 1; len < n; len *= 2)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].first.first = num[i];
            a[i].first.second = num[(i + len) % n];
            a[i].second = i;
        }
        sort(a, a + n);
        new_num[a[0].second] = 0;
        for (int i = 1; i < n; i++)
        {
            new_num[a[i].second] = new_num[a[i - 1].second];
            if (num[a[i].second] != num[a[i - 1].second] || num[(a[i].second + len) % n] != num[(a[i - 1].second + len) % n])
                new_num[a[i].second]++;
        }
        for (int i = 0; i < n; i++)
            num[i] = new_num[i];
    }
    for (int i = 0; i < n; i++)
    {
        suf[i] = a[i].second;
        num[a[i].second] = i;
    }
}

void build_lcp(string& s)
{
    for (int i = 0; i < n - 1; i++)
    {
        int e = 0;
        int j1 = suf[i];
        int j2 = suf[i + 1];
        while (e < n && s[(j1 + e) % n] == s[(j2 + e) % n])
            e++;
        lcp[i] = e;
    }
}

int find_len(string& s, int i)
{
    int j = num[i];
    int left = j - 1;
    int right = j;
    int ans = 0;
    for (int len = n; len >= 1; len--)
    {
        while (left >= 0 && lcp[left] >= len)
        {
            if (suf[left] < i)
                ans = max(ans, min(len, i - suf[left]));
            left--;
        }
        while (right < n - 1 && lcp[right] >= len)
        {
            right++;
            if (suf[right] < i)
                ans = max(ans, min(len, i - suf[right]));
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ON_PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ON_PC
    string s;
    cin >> n >> a1 >> b1 >> s;
    build_suf(s);
    build_lcp(s);
    for (int i = 1; i <= n; i++)
        dp[i] = inf;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + a1);
        int len = min(find_len(s, i), n - i);
        for (int e = 0; e < len; e++)
        {
            dp[i + e + 1] = min(dp[i + e + 1], dp[i] + b1);
        }
    }
    cout << dp[n];
}