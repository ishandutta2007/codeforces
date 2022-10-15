#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 5555;

string s, a, b;
int n;
unsigned int h[MAXN];
bool f[MAXN], g[MAXN];
int k[MAXN];
set <unsigned int> S;

int run(string c, bool *f)
{
    int m = c.size();
    c = " " + c + "@" + s;
    k[1] = 0;
    for (int i = 2; i < (int)c.size(); i++)
    {
        int x = k[i - 1];
        while (x && c[x + 1] != c[i]) x = k[x];
        x += c[x + 1] == c[i];
        if (x == m)
            f[i - m - m] = true;
        k[i] = x;
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> s >> a >> b;

    run(a, f);
    run(b, g);

    unsigned int p = 1;
    long long ans = 0;
    for (int l = 1; l <= s.size(); l++)
    {
        p *= 59;
        for (int i = 1; i <= s.size(); i++)
        {
            h[i] = h[i - 1] * 59 + s[i - 1] - 'a';
            if (l < i) h[i] -= p * (s[i - l - 1] - 'a');
        }

        if (l < a.size() || l < b.size()) continue;

        S.clear();
        for (int i = l; i <= s.size(); i++)
            if (f[i - l + 1] && g[i - (int)b.size() + 1])
                S.insert(h[i]);
        ans += S.size();
    }
    cout << ans << endl;
    return 0;
}