#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int  m, n, i, s, f, t, res;
    cin >> n >> m;
    m--;
    for (i = 0; i < n; i++)
    {
        cin >> s >> f >> t;
        s--;
        f--;
        if (s == f)
        {
            cout << t << "\n";
        }
        else
        {

        res = t;
        t = t % (m * 2);
        if (t <= m)
        {
            if (s >= t)
            {
                res += s - t;
                if (f >= s)
                    res += f - s;
                else
                    res += (m - s) + (m - f);
            }
            else
            {
                res += (m - t) + (m - s);
                if (s >= f)
                    res += s - f;
                else
                    res += s + f;
            }
        }
        else
        {
            t = m - (t % m);
            if (s <= t)
            {
                res += t - s;
                if (s >= f)
                    res += s - f;
                else
                    res += s + f;
            }
            else
            {
                res += t + s;
                if (s <= f)
                    res += f - s;
                else
                    res += m - s + m - f;
            }

        }
        cout << res << "\n";
        }
    }
    return 0;
}