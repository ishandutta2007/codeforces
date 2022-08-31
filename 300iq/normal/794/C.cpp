/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    int n = s.size();
    while (s.size() > n / 2 + n % 2)
    {
        s.pop_back();
    }
    while (t.size() > n / 2)
    {
        t.pop_back();
    }
    int a = 0, b = (int) s.size() - 1;
    int c = 0, d = (int) t.size() - 1;
    int last = -1;
    string cur = "";
    for (int i = 0; i < n; i++)
    {
        cur += '?';
    }
    int x = 0, y = n - 1;
    for (int it = 0; it < n; it++)
    {
        x = min(x, y);
        y = max(x, y);
        a = min(a, b);
        b = max(b, a);
        c = min(c, d);
        d = max(c, d);
        if (it % 2 == 0)
        {
            if (s[a] < t[c])
            {
                cur[x++] = s[a++];
            }
            else
            {
                cur[y--] = s[b--];
            }
        }
        else
        {
            if (s[a] >= t[c])
            {
                cur[y--] = t[d--];
            }
            else
            {
                cur[x++] = t[c++];
            }
        }
    }
    cout << cur << '\n';
}