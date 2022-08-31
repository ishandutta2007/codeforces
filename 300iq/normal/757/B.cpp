#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int cnt[N];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i != 1)
                {
                    cnt[i]++;
                }
                if (i != x / i)
                {
                    cnt[x / i]++;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, cnt[i]);
    }
    cout << ans << '\n';
}