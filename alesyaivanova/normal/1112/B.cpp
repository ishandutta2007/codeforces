#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 1009;
int a[MAX_N];
int n, k;
pair<int, int> q[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ON_PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ON_PC
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = 0;
    for (int i = 0; i < k; i++)
        q[i].second = -1;
    int j = 0;
    int m = 0;
    set<int> ans;
    while (true)
    {
        if (j == n)
        {
            int cnt = 0;
            for (int i = 0; i < k; i++)
            {
                if (q[i].second == -1)
                    cnt++;
            }
            if (cnt == k)
                break;
        }
        for (int i = 0; i < k; i++)
        {
            if (q[i].second != -1)
            {
                q[i].first--;
                int y = 100 * m;
                int t = y / n;
                if (y - t * n >= (t + 1) * n - y)
                    t++;
                if (a[q[i].second] - q[i].first == t)
                    ans.insert(q[i].second);
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (q[i].first == 0 && q[i].second != -1)
            {
                m++;
                q[i].second = -1;
            }
            if (q[i].second == -1 && j < n)
            {
                q[i].first = a[j];
                q[i].second = j;
                j++;
            }
        }
    }
    cout << ans.size();
}