#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 100005;

int n, k;
int a[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = a[n] - a[1];
    for (int maxu = 0; maxu <= a[n]; ++maxu)
    {
        int minu = maxu;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] / k > maxu)
            {
                minu = -1;
                break;
            }
            int l = 1, r = k;
            int u;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (a[i] / m <= maxu)
                {
                    u = a[i] / m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            minu = min(minu, u);
        }
        if (minu != -1)
            ans = min(ans, maxu - minu);
    }
    cout << ans << "\n";
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}