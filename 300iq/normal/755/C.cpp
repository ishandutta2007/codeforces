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
    int n, x;
    cin >> n;
    set <int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == i + 1)
        {
            ans++;
            continue;
        }
        s.insert(x);
    }
    cout << (ans + s.size() / 2) << '\n';
}