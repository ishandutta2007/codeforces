#include <bits/stdc++.h>
using namespace std;
const int N = 1003, INF = 1000000009;
struct ban
{
    int l, r;
};

int n, k;
int a[N];

int t[N];

ban b[N];

int ta[N * N];
int p[N * N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int minu = INF;
        int mini;
        for (int j = 1; j <= k; ++j)
        {
            if (t[j] < minu)
            {
                minu = t[j];
                mini = j;
            }
        }
        b[i].l = minu;
        b[i].r = minu + a[i] - 1;
        t[mini] += a[i];
        ta[b[i].r + 1]++;
    }

    p[0] = ta[0];
    for (int i = 1; i < N * N; ++i)
    {
        p[i] = ta[i] + p[i - 1];
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = b[i].l; j <= b[i].r; ++j)
        {
            if (i == 2 && j == 50)
                cout << "";
            double d = p[j] * 1.0 / n;
            d *= 100;
            d += 0.5;
            if (j - b[i].l + 1 == (int)d)
            {
                ++ans;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}