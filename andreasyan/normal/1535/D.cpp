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
const int N = 1000006;

int k;
char a[N];
int q[N];
int p[N];
int rp[N];

void solv()
{
    cin >> k;
    cin >> (a + 1);

    for (int i = 1; i < (1 << k); ++i)
        p[i] = i;

    int u = 1;
    for (int i = k - 1; i >= 0; --i)
    {
        reverse(a + u, a + u + (1 << i));
        reverse(p + u, p + u + (1 << i));
        u += (1 << i);
    }
    reverse(a + 1, a + (1 << k));
    reverse(p + 1, p + (1 << k));
    for (int i = 1; i < (1 << k); ++i)
        rp[p[i]] = i;

    for (int x = (1 << k) - 1; x >= 1; --x)
    {
        if (x * 2 < (1 << k))
        {
            if (a[x] == '?')
                q[x] = q[x * 2] + q[x * 2 + 1];
            else if (a[x] == '0')
                q[x] = q[x * 2];
            else
                q[x] = q[x * 2 + 1];
        }
        else
        {
            if (a[x] == '?')
                q[x] = 2;
            else
                q[x] = 1;
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x;
        char c;
        cin >> x >> c;
        x = rp[x];
        a[x] = c;
        while (x)
        {
            if (x * 2 < (1 << k))
            {
                if (a[x] == '?')
                    q[x] = q[x * 2] + q[x * 2 + 1];
                else if (a[x] == '0')
                    q[x] = q[x * 2];
                else
                    q[x] = q[x * 2 + 1];
            }
            else
            {
                if (a[x] == '?')
                    q[x] = 2;
                else
                    q[x] = 1;
            }
            x /= 2;
        }

        cout << q[1] << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}