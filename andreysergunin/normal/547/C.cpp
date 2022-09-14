#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 600000;
const int MAXK = 600000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int a[MAXN];
    int b[MAXN];
    int d[MAXN];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        d[i] = 0;
        b[i] = 0;
    }

    int t[MAXN];
    for (int i = 0; i < MAXK; i++)
        t[i] = 0;

    for (int i = 2; i < MAXK; i++)
    {
        if (t[i] == 0)
        {
            for (int j = i; j < MAXK; j += i)
                t[j]++;
        }
    }

    vector<int> f[MAXN];
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j * j <= a[i]; j++)
            while (a[i] % (j * j) == 0)
                a[i] /= j;
        for (int j = 1; j * j <= a[i]; j++)
            if (a[i] % j == 0)
            {
                f[i].push_back(j);
                if (j * j != a[i])
                    f[i].push_back(a[i] / j);
            }
    }
    long long ans = 0;

    long long h = 0;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        q--;
        if (b[q] == 0)
        {
            h++;
            b[q] = 1;
            long long k = 0;
            for (int j = 0; j < (int)f[q].size(); j++)
            {
                if (f[q][j] != 1)
                {
                    if (t[f[q][j]] % 2 == 0)
                        k += d[f[q][j]];
                    else
                        k -= d[f[q][j]];
                }
            }
            ans += abs(k);
            for (int j = 0; j < (int)f[q].size(); j++)
                d[f[q][j]]++;
        }
        else
        {
            h--;
            b[q] = 0;
            for (int j = 0; j < (int)f[q].size(); j++)
                d[f[q][j]]--;
            long long k = 0;
            for (int j = 0; j < (int)f[q].size(); j++)
            {
                if (f[q][j] != 1)
                {
                    if (t[f[q][j]] % 2 == 0)
                        k += d[f[q][j]];
                    else
                        k -= d[f[q][j]];
                }
            }
            ans -= abs(k);
        }
        cout << h * (h - 1) / 2 - ans << endl;
    }
    return 0;
}