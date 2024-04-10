#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int k[3];
int n;
bool c[N][3];

int p00[N], s01[N];

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &k[i]);
        n += k[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < k[i]; ++j)
        {
            int x;
            scanf("%d", &x);
            c[x][i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        p00[i] = p00[i - 1];
        if (!c[i][0])
            p00[i]++;
    }
    for (int i = n; i >= 1; --i)
    {
        s01[i] = s01[i + 1];
        if (c[i][0])
            s01[i]++;
    }
    int ans = N * 3;
    int minu = 0;
    int s = 0;
    for (int i = n; i >= 0; --i)
    {
        ans = min(ans, p00[i] + s01[i + 1] + minu);
        if (c[i][2])
        {
            ++minu;
        }
        if (c[i][1])
        {
            ++s;
        }
        minu = min(minu, s);
    }
    cout << ans << endl;
    return 0;
}