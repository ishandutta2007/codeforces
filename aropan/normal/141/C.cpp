#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define X first
#define S second

const int MAXN = 3007;

int n;
pair <int, string> a[MAXN];
int f[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        f[i] = i + 1;
        cin >> a[i].S >> a[i].X;
    }

    sort(a, a + n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i < a[i].X)
        {
            puts("-1");
            return 0;
        }

        for (int j = a[i].X - 1; j >= 0; j--)
            swap(f[i - j], f[i - j - 1]);
    }

    for (int i = 0; i < n; i++)
        cout << a[i].S << " " <<  f[i] << endl;
    return 0;
}