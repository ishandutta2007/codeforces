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
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[0] && a[i] != a.back())
        {
            ans++;
        }
    }
    cout << ans << '\n';
}