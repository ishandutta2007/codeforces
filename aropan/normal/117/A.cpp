#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long n, m;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        long long s, f, t;
        cin >> s >> f >> t;

        if (s != f)
        {
            long long x, y;

            long long k = m + m - 2;

            x = s - 1, y = m - s + m - 1;
            t = min((t - x + k - 1) / k * k + x, (t - y + k - 1) / k * k + y);

            x = f - 1, y = m - f + m - 1;
            t = min((t - x + k - 1) / k * k + x, (t - y + k - 1) / k * k + y);
        }


        cout << t << endl;
    }

    return 0;
}