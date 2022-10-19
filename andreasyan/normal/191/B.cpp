#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int i;
    long long d;
};
bool operator<(const ban& a, const ban& b)
{
    return a.d < b.d;
}

int n, k;
long long b;
ban a[N];
long long t[N];
bool c[N];

int main()
{
    cin >> n >> k;
    cin >> b;
    --n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].d;
        a[i].i = i;
        t[i] = a[i].d;
    }
    cin >> a[n + 1].d;
    a[n + 1].i = n + 1;
    sort(a + 1, a + n + 1);
    long long bb = 0;
    for (int i = n; i >= n - k + 1; --i)
    {
        c[a[i].i] = true;
        bb += a[i].d;
    }
    if (b >= bb)
    {
        cout << n + 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            cout << i << endl;
            return 0;
        }
        else
        {
            if (b - (bb - a[n - k + 1].d) - t[i] < 0)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << n + 1 << endl;
    return 0;
}