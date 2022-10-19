#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    int n;
    cin >> n;

    int l = 1, r = n;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        cout << "? 1 " << m << endl;
        int q = 0;
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            if (x <= m)
                ++q;
        }

        if (q % 2 == 1)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << "! " << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}