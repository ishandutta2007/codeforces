#include <bits/stdc++.h>
using namespace std;
const int N = 600005;
long long P = 5;

int mrand()
{
    int y = 0;
    for (int i = 0; i < 10; ++i)
        y += rand();
    return y;
}

void mshuf(vector<int>& v)
{
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int j = mrand() % (i + 1);
        swap(v[i], v[j]);
    }
}

vector<int> v[N];

long long ast[N];

int n;
char a[N];

set<long long> s;

int main()
{
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = ast[i - 1] * P;

    int m, q;
    cin >> m >> q;
    while (m--)
    {
        cin >> a;
        n = strlen(a);
        if (v[n].empty())
        {
            for (int i = 0; i < n; ++i)
                v[n].push_back(i);
            mshuf(v[n]);
        }
        long long x = 0;
        for (int i = 0; i < n; ++i)
        {
            x = (x + (a[v[n][i]] - 'a' + 1) * ast[i]);
        }
        s.insert(x);
    }
    while (q--)
    {
        cin >> a;
        n = strlen(a);
        if (v[n].empty())
        {
            cout << "NO" << endl;
            continue;
        }
        long long x = 0;
        for (int i = 0; i < n; ++i)
            x = (x + (a[v[n][i]] - 'a' + 1) * ast[i]);
        bool z = false;
        for (int i = 0; i < n; ++i)
        {
            x = (x - (a[v[n][i]] - 'a' + 1) * ast[i]);
            for (int j = 1; j <= 3; ++j)
            {
                if (j != (a[v[n][i]] - 'a' + 1))
                {
                    x = (x + j * ast[i]);
                    if (s.find(x) != s.end())
                        z = true;
                    x = (x - j * ast[i]);
                }
            }
            x = (x + (a[v[n][i]] - 'a' + 1) * ast[i]);
        }
        if (z)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}