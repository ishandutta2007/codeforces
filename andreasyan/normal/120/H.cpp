#include <bits/stdc++.h>
using namespace std;
const int N = 202;
const long long P = 31;

int n;
char a[N][20];

map<long long, int> mp;
int z[N][5];

bool c[N];
bool dfs(int x)
{
    if (c[x] == true)
        return false;
    c[x] = true;
    long long h = 0;
    for (int i = 0; i < strlen(a[x]); ++i)
    {
        h += (a[x][i] - 'a' + 1);
        if (mp.find(h) == mp.end() || dfs(mp[h]))
        {
            mp[h] = x;
            z[x][0] = i;
            z[x][1] = -1;
            return true;
        }
        for (int j = i + 1; j < strlen(a[x]); ++j)
        {
            h += (a[x][j] - 'a' + 1) * P;
            if (mp.find(h) == mp.end() || dfs(mp[h]))
            {
                mp[h] = x;
                z[x][0] = i;
                z[x][1] = j;
                z[x][2] = -1;
                return true;
            }
            for (int k = j + 1; k < strlen(a[x]); ++k)
            {
                h += (a[x][k] - 'a' + 1) * P * P;
                if (mp.find(h) == mp.end() || dfs(mp[h]))
                {
                    mp[h] = x;
                    z[x][0] = i;
                    z[x][1] = j;
                    z[x][2] = k;
                    z[x][3] = -1;
                    return true;
                }
                for (int t = k + 1; t < strlen(a[x]); ++t)
                {
                    h += (a[x][t] - 'a' + 1) * P * P * P;
                    if (mp.find(h) == mp.end() || dfs(mp[h]))
                    {
                        mp[h] = x;
                        z[x][0] = i;
                        z[x][1] = j;
                        z[x][2] = k;
                        z[x][3] = t;
                        z[x][4] = -1;
                        return true;
                    }
                    h -= (a[x][t] - 'a' + 1) * P * P * P;
                }
                h -= (a[x][k] - 'a' + 1) * P * P;
            }
            h -= (a[x][j] - 'a' + 1) * P;
        }
        h -= (a[x][i] - 'a' + 1);
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        z[i][0] = -1;
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(c, 0, sizeof c);
        dfs(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (z[i][0] == -1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; z[i][j] != -1; ++j)
            cout << a[i][z[i][j]];
        cout << endl;
    }
    return 0;
}