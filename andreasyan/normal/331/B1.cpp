#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];
int b[N];

int t[N], tt[N];

void ubd(int x, int y)
{
    if (!(0 <= tt[x] + y && tt[x] + y <= 1))
        return;
    tt[x] += y;
    ++x;
    while (x <= n + 1)
    {
        t[x] += y;
        x += (x & (-x));
    }
}
int qry(int l, int r)
{
    ++r;
    if (l > r)
        return 0;
    int ans = 0;
    while (r > 0)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    while (l > 0)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x] = i;
        if (a[x - 1] == 0)
            ubd(x, 1);
        b[i] = x;
    }
    a[0] = N;
    a[n + 1] = N;
    int q;
    cin >> q;
    while (q--)
    {
        int ty, x, y;
        cin >> ty >> x >> y;
        if (ty == 1)
        {
            cout << qry(x + 1, y) + 1 << endl;
            /*int ans = 1;
            for (int i = x + 1; i <= y; ++i)
            {
                if (a[i] < a[i - 1])
                    ++ans;
            }
            cout << ans << endl;*/
        }
        else
        {
            swap(b[x], b[y]);
            x = b[x];
            y = b[y];
            if (a[x] < a[x - 1])
                ubd(x, -1);
            if (a[y] < a[y - 1])
                ubd(y, -1);
            if (a[x + 1] < a[x])
                ubd(x + 1, -1);
            if (a[y + 1] < a[y])
                ubd(y + 1, -1);

            swap(a[x], a[y]);

            if (a[x] < a[x - 1])
                ubd(x, 1);
            if (a[y] < a[y - 1])
                ubd(y, 1);
            if (a[x + 1] < a[x])
                ubd(x + 1, 1);
            if (a[y + 1] < a[y])
                ubd(y + 1, 1);
            /*for (int i = 1; i <= n; ++i)
            {
                if (i == 3 && qry(0, n + 1, i, i, 1) < 0 && a[i] < a[i - 1])
                    assert(false);
            }*/
        }
    }
    return 0;
}