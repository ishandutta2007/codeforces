/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

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
    vector <int> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i - 1] * (ll) 2) % M;
    }
    int cnt = 0;
    int ans = 0;
    for (auto c : s)
    {
        if (c == 'a')
        {
            cnt++;
        }
        else
        {
            if (cnt == 0)
            {
                continue;
            }
            else
            {
                int f = (p[cnt] + M - 1) % M;
                ans = (ans + f) % M;
            }
        }
    }
    cout << ans << '\n';
}