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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    string s;
    cin >> s;
    if (s[a] == s[b])
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << 1 << '\n';
    }
}