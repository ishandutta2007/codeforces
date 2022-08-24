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
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    for (char c = 'z'; c >= 'a'; c--)
    {
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                last = i;
            }
        }
        for (; i <= last; i++)
        {
            if (s[i] == c)
            {
                cout << c;
            }
        }
    }
}