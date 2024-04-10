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
    int n, m;
    cin >> n >> m;
    unordered_set <string> a, b;
    a.rehash(n);
    b.rehash(m);
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        a.insert(t);
    }
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        b.insert(t);
    }
    int it = 0;
    bool good = 0;
    while (1)
    {
        good = 0;
        if (a.size() == 0)
        {
            cout << "NO\n";
            return 0;
        }
        for (auto c : a)
        {
            if (b.count(c))
            {
                good = 1;
                a.erase(c);
                b.erase(c);
                break;
            }
        }
        if (!good)
        {
            a.erase(a.begin());
        }
        if (b.size() == 0)
        {
            cout << "YES\n";
            return 0; 
        }
        good = 0;
        for (auto c : b)
        {
            if (a.count(c))
            {
                good = 1;
                a.erase(c);
                b.erase(c);
                break;
            }
        }
        if (!good)
        {
            b.erase(b.begin());
        }
    }
}