#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n;
int m[N];
string a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m[i] = a[i].size();
    }
    for (int i = n - 1; i >= 1; --i)
    {
        bool z = false;
        for (int j = 0; j < min(m[i], m[i + 1]); ++j)
        {
            if (a[i][j] != a[i + 1][j])
            {
                z = true;
                if (a[i][j] > a[i + 1][j])
                {
                    m[i] = j;
                }
                break;
            }
        }
        if (!z)
        {
            if (m[i] > m[i + 1])
                m[i] = m[i + 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m[i]; ++j)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}