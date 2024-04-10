#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = 1000000009;

int n;
char s1[N];
char s2[N];

const int m = 26;
int a[m][m], b[m][m];
char t[m][m];

char s[N];
int main()
{
    cin >> s1;
    cin >> s2;
    n = strlen(s1);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i != j)
                a[i][j] = INF;
        }
    }
    int mm;
    cin >> mm;
    while (mm--)
    {
        char x, y;
        int g;
        cin >> x >> y >> g;
        a[x - 'a'][y - 'a'] = min(a[x - 'a'][y - 'a'], g);
    }
    if (strlen(s1) != strlen(s2))
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int k = 0; k < m; ++k)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            b[i][j] = INF;
            for (int k = 0; k < m; ++k)
            {
                if (a[i][k] + a[j][k] < b[i][j])
                {
                    b[i][j] = a[i][k] + a[j][k];
                    t[i][j] = 'a' + k;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[s1[i] - 'a'][s2[i] - 'a'] == INF)
        {
            cout << "-1" << endl;
            return 0;
        }
        ans += b[s1[i] - 'a'][s2[i] - 'a'];
        s[i] = t[s1[i] - 'a'][s2[i] - 'a'];
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}