#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 666;

struct palindromic_tree
{
    int len[MAXN], link[MAXN], cnt[MAXN];
    char S[MAXN];
    vector<pair<char, int>> to[MAXN];

    int n, last, sz;

    void clear()
    {
        fill(to, to + MAXN, vector<pair<char, int>>());
        memset(len , 0, sizeof(len ));
        memset(link, 0, sizeof(link));
        memset(cnt , 0, sizeof(cnt ));
        memset(S   , 0, sizeof(S   ));
        n = last = 0;
        link[0] = 1;
        len[1] = -1;
        S[n++] = 27;
        sz = 2;
    }

    palindromic_tree()
    {
        clear();
    }

    int get_link(int v)
    {
        while(S[n - len[v] - 2] != S[n - 1]) v = link[v];
        return v;
    }

    int tr(int v, int c)
    {
        for(auto it: to[v])
            if(it.first == c) return it.second;
        return 0;
    }

    int add_letter(int c)
    {
        S[n++] = c;
        int cur = get_link(last);
        if(!tr(cur, c))
        {
            len [sz] = len[cur] + 2;
            link[sz] = tr(get_link(link[cur]), c);
            to[cur].push_back({c, sz++});
        }
        last = tr(cur, c);
        return cnt[last] = cnt[link[last]] + 1;
    }
} me;

const int MOD = 51123987;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int start[n], finish[n];

    for(int i = 0; i < n; i++)
        finish[i] = me.add_letter(s[i] - 'a');

    me.clear();
    for(int i = 0; i < n; i++)
        start[n - i - 1] = me.add_letter(s[n - i - 1] - 'a');

    int64_t ans = accumulate(start, start + n, 0ll) % MOD;
    ans = ans * (ans - 1) / 2 % MOD;
    int64_t sum = 0;
    for(int i = 1; i < n; i++)
    {
        sum = (sum + finish[i - 1]) % MOD;
        ans = (ans - sum * start[i]) % MOD;
        if(ans < 0) ans += MOD;
    }
    cout << ans << "\n";
}