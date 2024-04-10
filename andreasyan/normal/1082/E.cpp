#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, c;
int a[N];
vector<int> b[N];
int p[N];

int ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == c)
            p[i]++;
    }
    ans = p[n];
    for (int i = 1; i < N; ++i)
    {
        if (i == c)
            continue;
        int minu = 0;
        for (int j = 0; j < b[i].size(); ++j)
        {
            minu = min(minu, (-(p[b[i][j]] - p[b[i][0] - 1]) + j + 1));
            ans = max(ans, p[n] + (-(p[b[i][j]] - p[b[i][0] - 1]) + j + 1) - minu);
            if (j != b[i].size() - 1)
            {
                minu = min(minu, (-(p[b[i][j + 1] - 1] - p[b[i][0] - 1]) + j + 1));
                ans = max(ans, p[n] + (-(p[b[i][j + 1] - 1] - p[b[i][0] - 1]) + j + 1) - minu);
            }
        }
    }
    cout << ans << endl;
    return 0;
}