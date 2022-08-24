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
    string s;
    cin >> s;
    vector <int> kek(255, -1);
    for (int i = 0; i < (int) s.size(); i++)
    {
        kek[s[i]] = i;
    }
    int n = s.size();
    int v = 0;
    string ans = "";
    string t = "";
    for (char c = 'a'; c <= 'z'; c++)
    {
        while (t.size() > 0 && t.back() <= c)
        {
            ans += t.back();
            t.pop_back();
        }
        while (v < n)
        {
            if (s[v] == c)
            {
                ans += s[v];
            }
            if (kek[c] >= v)
            {
                if (s[v] != c)
                {
                    t += s[v];
                }
                v++; 
            }
            else
            {
                break;
            }
        }
    }
    while (t.size() > 0)
    {
        ans += t.back();
        t.pop_back();
    }
    cout << ans << '\n';
}