#include <bits/stdc++.h>
using namespace std;
const int N = 102, m = 30, M = 10000007;

int n;
int a[N];

int z;
map<int, int> t[M];
int u[M];

int uu;
int q[N];
int cq[N];
void rec(int x, int f)
{
    if (x == f)
    {
        memcpy(cq, q, sizeof q);
        if (f == 15)
        {
            int minu = q[0];
            for (int i = 1; i < n; ++i)
                minu = min(minu, q[i]);
            for (int i = 0; i < n; ++i)
                q[i] -= minu;
            int pos = 0;
            for (int i = 0; i < n; ++i)
            {
                if (t[pos].find(q[i]) == t[pos].end())
                    t[pos][q[i]] = ++z;
                pos = t[pos][q[i]];
            }
            u[pos] = uu;
        }
        else
        {
            int minu = q[0];
            for (int i = 1; i < n; ++i)
                minu = min(minu, q[i]);
            for (int i = 0; i < n; ++i)
                q[i] -= minu;
            int maxu = q[0];
            for (int i = 1; i < n; ++i)
                maxu = max(maxu, q[i]);
            for (int i = 0; i < n; ++i)
                q[i] = maxu - q[i];
            int pos = 0;
            bool z = true;
            for (int i = 0; i < n; ++i)
            {
                if (t[pos].find(q[i]) == t[pos].end())
                {
                    z = false;
                    break;
                }
                pos = t[pos][q[i]];
            }
            if (z)
            {
                cout << (uu ^ u[pos]) << endl;
                exit(0);
            }
        }
        memcpy(q, cq, sizeof cq);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] & (1 << x)))
            ++q[i];
    }
    rec(x + 1, f);
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] & (1 << x)))
            --q[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (!(a[i] & (1 << x)))
            ++q[i];
    }
    uu ^= (1 << x);
    rec(x + 1, f);
    for (int i = 0; i < n; ++i)
    {
        if (!(a[i] & (1 << x)))
            --q[i];
    }
    uu ^= (1 << x);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    rec(0, 15);
    rec(15, 30);
    cout << -1 << endl;
    return 0;
}