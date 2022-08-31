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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
}