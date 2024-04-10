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
    vector <int> p(n);
    vector <bool> used(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }
    vector <int> b(n);
    int gg = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        gg += b[i];
    }
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            int sm = 0;
            int j = i;
            while (!used[j])
            {
                sm++;
                used[j] = 1;
                j = p[j];
            }
            mx = max(mx, sm);
            cnt++;
        }
    }
    int ans = (cnt == 1 ? 0 : cnt);
    if (gg % 2 == 0)
    {
        ans++;
    }
    printf("%d\n", ans); 
}