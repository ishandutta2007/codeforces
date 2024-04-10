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
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    vector <int> x(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (b < x[i] && x[i] < c)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}