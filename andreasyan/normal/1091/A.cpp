#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = -1;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    for (int xx = 1; xx <= x; ++xx)
    {
        for (int yy = 1; yy <= y; ++yy)
        {
            for (int zz = 1; zz <= z; ++zz)
            {
                if (yy == xx + 1 && zz == yy + 1)
                    ans = max(ans, xx + yy + zz);
            }
        }
    }
    cout << ans << endl;
    return 0;
}