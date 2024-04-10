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
    string a, b;
    cin >> a >> b;
    cout << a << ' ' << b << '\n';
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        if (s == a)
        {
            a = t;
        }
        else if (s == b)
        {
            b = t;
        }
        cout << a << ' ' << b << '\n';
    }
}