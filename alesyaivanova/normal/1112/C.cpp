#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 500009;
int a[MAX_N];
int b[MAX_N];
int m, k, n, ss;
int cnt[MAX_N];
int cur[MAX_N];

bool check(int i, int e)
{
    int w = i - (i / k) * k;
    int len = max(e - i, k);
    w += len - k;
    e = max(e, i + k);
    if (w > m - n * k)
        return false;
    if (i / k + 1 + (m - e) / k < n)
        return false;
    if (e > m)
        return false;
    cout << w << "\n";
    for (int j = 0; j < i - (i / k) * k; j++)
        cout << j + 1 << " ";
    w = len - k;
    for (int j = 0; j < MAX_N; j++)
        cur[j] = 0;
    for (int j = i; j < e && w; j++)
    {
        int x = a[j];
        cur[x]++;
        if (cur[x] > cnt[x])
        {
            cout << j + 1 << " ";
            w--;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ON_PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ON_PC
    cin >> m >> k >> n >> ss;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    set<int> s;
    for (int i = 0; i < ss; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
        cnt[b[i]]++;
    }
    int e = 0;
    for (int i = 0; i < m; i++)
    {
        if (i > 0)
        {
            int x = a[i - 1];
            cur[x]--;
            if (cur[x] < cnt[x])
                s.insert(x);
        }
        while (e < m && !s.empty())
        {
            int x = a[e];
            cur[x]++;
            if (cur[x] >= cnt[x])
                s.erase(x);
            e++;
        }
        if (!s.empty())
            break;
        if (check(i, e))
            return 0;
    }
    cout << -1;
}