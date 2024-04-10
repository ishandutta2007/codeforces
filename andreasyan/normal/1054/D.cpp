#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
int a[N];
int p[N];

int hak(int x)
{
    int y = 0;
    for (int i = 0; i < k; ++i)
    {
        if (!(x & (1 << i)))
            y |= (1 << i);
    }
    return y;
}

map<int, int> mp;
map<int, bool> c;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    mp[p[0]]++;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] ^ a[i];
        mp[p[i]]++;
    }

    long long ans = 1LL * (n + 1) * n / 2;
    for (int i = 0; i <= n; ++i)
    {
        if (!c[hak(p[i])] && !c[p[i]])
        {
            c[p[i]] = true;
            long long x = mp[p[i]] + mp[hak(p[i])];
            ans -= ((x / 2) * (x / 2 - 1) / 2);
            ans -= ((x / 2 + x % 2) * (x / 2 + x % 2 - 1) / 2);
        }
    }

    cout << ans << endl;
    return 0;
}