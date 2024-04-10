#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;

int n, v;

int main()
{
    cin >> n >> v;
    int ans = 0;
    int vv = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1)
            vv--;

        int ar = min(v - vv, n - i - vv);
        ans += (i * ar);
        vv += ar;
    }
    cout << ans << endl;
    return 0;
}