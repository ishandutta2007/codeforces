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
const int N = 12;

char a[N];

void solv()
{
    cin >> a;

    int ans = 10;

    {
        int q1 = 0;
        int q2 = 0;
        for (int i = 0; i < 10; ++i)
        {
            int qq1 = 0;
            int qq2 = 0;
            for (int j = i; j < 10; ++j)
            {
                if (j % 2 == 0)
                    ++qq1;
                else
                    ++qq2;
            }
            if (q1 > q2 + qq2)
            {
                ans = min(ans, i);
                break;
            }
            if (q2 > q1 + qq1)
            {
                ans = min(ans, i);
                break;
            }
            if (i % 2 == 0)
            {
                if (a[i] == '1' || a[i] == '?')
                {
                    ++q1;
                }
            }
            else
            {
                if (a[i] == '1')
                {
                    ++q2;
                }
            }
        }
    }

    {
        int q1 = 0;
        int q2 = 0;
        for (int i = 0; i < 10; ++i)
        {
            int qq1 = 0;
            int qq2 = 0;
            for (int j = i; j < 10; ++j)
            {
                if (j % 2 == 0)
                    ++qq1;
                else
                    ++qq2;
            }
            if (q1 > q2 + qq2)
            {
                ans = min(ans, i);
                break;
            }
            if (q2 > q1 + qq1)
            {
                ans = min(ans, i);
                break;
            }
            if (i % 2 == 0)
            {
                if (a[i] == '1')
                {
                    ++q1;
                }
            }
            else
            {
                if (a[i] == '1' || a[i] == '?')
                {
                    ++q2;
                }
            }
        }
    }

    cout << ans << "\n";
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