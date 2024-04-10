#include <bits/stdc++.h>

using namespace std;

int n, k, m, t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k >> m >> t;
    for (int i = 1, u, v; i <= t; i++)
    {
        cin >> u >> v;
        if (u == 0)
        {
            if (k >= v + 1)
            {
                n = n - v;
                k = k - v;
            }
            else
                n = v;
        }
        else
        {
            n++;
            if (v <= k)
                k++;
        }
        cout << n << " " << k << endl;
    }
    return 0;
}