#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n, m;
int a[N];

bool stg(int x)
{
    int y = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] + x >= m)
        {
            if (a[i] + x - m >= y)
                continue;
            y = max(y, a[i]);
        }
        else
        {
            if (y > a[i] + x)
                return false;
            y = max(y, a[i]);
        }
    }
    return true;
}

int byn()
{
    int l = 0, r = m - 1;
    while ((r - l) > 3)
    {
        int mid = (l + r) / 2;
        if (stg(mid))
            r = mid;
        else
            l = mid;
    }
    for (int mid = l; mid <= r; ++mid)
        if (stg(mid))
            return mid;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << byn() << endl;
    return 0;
}