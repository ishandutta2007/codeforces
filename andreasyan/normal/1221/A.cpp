#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int q[N];

bool solv()
{
    memset(q, 0, sizeof q);
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x > 2048)
            continue;
        int u = 0;
        while (x % 2 == 0)
        {
            ++u;
            x /= 2;
        }
        q[u]++;
    }
    for (int i = 0; i < 11; ++i)
    {
        q[i + 1] += q[i] / 2;
    }
    return (q[11] > 0);
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}