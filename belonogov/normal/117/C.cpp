#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 5e3 + 2;
pair<int, int> b[MAXN];
int a[MAXN][MAXN];
int n;

int main()
{
     int n, i, j;
    char s[MAXN];
    cin >> n;
    for (i = 0; i < n; i++)
        b[i].second = i;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < n; j++)
        {
            if (s[j] == '0')
                a[i][j] = 0;
            else
                a[i][j] = 1;
            b[i].first += a[i][j];
        }
    }
    sort(b, b + n);
    for (i = 1; i < n; i++)
    {
        if (b[i].first == b[i - 1].first)
        {
            for (j = 0; j < n; j++)
                if (j != b[i].second && j != b[i-1].second &&
                     a[b[i].second][b[i-1].second] == a[b[i-1].second][j] && a[j][b[i].second] == a[b[i-1].second][j])
                {
                    if (a[b[i].second][b[i-1].second] == 1)
                        cout << b[i].second + 1 << " " << b[i-1].second + 1 << " " << j + 1;
                    else
                        cout << b[i].second + 1 << " " << j + 1 << " " <<b[i-1].second + 1;
                    return 0;
                }
        }
    }
    cout << -1;


    return 0;
}