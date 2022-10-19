#include <bits/stdc++.h>
using namespace std;
const int N = 402;

int n;

int b[N * N];
bool solv()
{
    memset(b, 0, sizeof b);
    cin >> n;
    int minu = N * N, maxu = 0;
    for (int i = 0; i < n * 4; ++i)
    {
        int x;
        cin >> x;
        b[x]++;
        maxu = max(maxu, x);
        minu = min(minu, x);
    }
    int s = minu * maxu;
    int j = N * N - 1;
    for (int i = 1; i < N * N; ++i)
    {
        if (!b[i])
            continue;
        while (!b[j])
            --j;
        if (i == j)
        {
            if (i * j != s)
                return false;
            if (b[i] % 4)
                return false;
            b[i] = 0;
        }
        else
        {
            if (i * j != s)
                return false;
            if (b[i] != b[j])
                return false;
            if (b[i] % 2)
                return false;
            b[i] = b[j] = 0;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
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