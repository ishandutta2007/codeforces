#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 502;
const int xx[4] = {1, -1, 1, -1};
const int yy[4] = {1, -1, -1, 1};

int n;
char a[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] != 'X')
                continue;
            bool z = true;
            for (int k = 0; k < 4; ++k)
            {
                int hi = i + yy[k], hj = j + xx[k];
                if (!(hi >= 0 && hi < n && hj >= 0 && hj < n && a[hi][hj] == 'X'))
                {
                    z = false;
                    break;
                }
            }
            if (z)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}