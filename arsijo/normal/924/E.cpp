#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e4 + 14;
const int MOD = 1e9 + 7;
const long long INF = 1e9 * 1ll * 1e9;

int n, l, r;

bool can[MaxN][MaxN];
bool used[MaxN];

pair<int, int> a[MaxN];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
        return a.second > b.second;
    if(a.second == 0)
        return false;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;

    int sum = 0;

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        sum += a[i].first;
    }

    for(int i = 1; i <= n; ++i)
        cin >> a[i].second;

    sort(a + 1, a + n + 1, cmp);

    can[n + 1][0] = true;

    for(int i = n; i; --i)
        for(int j = sum; j >= 0; --j)
            if(can[i + 1][j] || (j >= a[i].first && can[i + 1][j - a[i].first]))
            {
                can[i][j] = true;
            }

    int ans = 0;

    for(int i = l; i <= r && i <= sum; ++i)
        if(can[1][i])
        {
            int j = n;
            int h = i;

            for(int j = 1; j <= n; ++j)
                used[j] = false;

            while(!can[j][h])
                --j;

            for(; j <= n && h; ++j)
                if(!can[j + 1][h])
                {
                    used[j] = true;
                    h -= a[j].first;
                }

            int curAns = 0;

            h = i;

            for(int i = 1; i <= n && a[i].second == 1 && h <= r; ++i)
                if(!used[i])
                {
                    ++curAns;
                    h += a[i].first;
                }

            ans = max(curAns, ans);
        }

    cout << ans << '\n';


    return 0;
}