#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, z;
int a[N];

bool stg(int x)
{
    for (int l = 1, r = n - x + 1; l <= x && r <= n; ++l, ++r)
    {
        if (a[r] - a[l] < z)
            return false;
    }
    return true;
}

int byn()
{
    int l = 0, r = n / 2;
    while ((r - l) > 3)
    {
        int m = (l + r) / 2;
        if (stg(m))
            l = m;
        else
            r = m;
    }
    for (int m = r; m >= l; --m)
        if (stg(m))
            return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> z;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    cout << byn() << endl;
    return 0;
}