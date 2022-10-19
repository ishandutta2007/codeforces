#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n;
string a;

int bn, en;
string b, e;

int z[N * 2];
void f(string a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
        z[i] = 0;
    int r = -1;
    for (int i = 1; i < n; ++i)
    {
        if (i > r)
        {
            while (a[i + z[i]] == a[z[i]])
                ++z[i];
        }
        else
        {
            z[i] = min(n - i, z[r - i]);
            while (a[i + z[i]] == a[z[i]])
                ++z[i];
        }
        r = max(r, z[i]);
    }
}

bool ss[N], ee[N];

int zz;
map<int, int> bo[N * N];

int h[N][N];

set<int> ans[N];

int main()
{
    cin >> a;
    n = a.size();
    cin >> b;
    bn = b.size();
    cin >> e;
    en = e.size();

    f(b + "#" + a);
    for (int i = bn + 1; i < bn + 1 + n; ++i)
    {
        if (z[i] >= bn)
            ss[i - bn - 1] = true;
    }

    reverse(a.begin(), a.end());
    reverse(e.begin(), e.end());
    f(e + "#" + a);
    for (int i = en + 1; i < en + 1 + n; ++i)
    {
        if (z[i] >= en)
            ee[n - 1 - (i - en - 1)] = true;
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < n; ++i)
    {
        int pos = 0;
        for (int j = i; j < n; ++j)
        {
            if (bo[pos].find(a[j]) == bo[pos].end())
                bo[pos][a[j]] = zz++;
            pos = bo[pos][a[j]];
            h[i][j] = pos;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (!ss[i] || !ee[j] || (j - i + 1) < bn || (j - i + 1) < en)
                continue;
            ans[j - i + 1].insert(h[i][j]);
        }
    }

    int yans = 0;
    for (int i = 1; i <= n; ++i)
        yans += ans[i].size();

    cout << yans << endl;
    return 0;
}