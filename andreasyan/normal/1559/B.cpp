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
const int N = 102;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != '?' && a[i + 1] == a[i])
            ++ans;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '?')
        {
            int l = i;
            int r = i;
            while (a[r + 1] == '?')
                ++r;
            if (l == 1 || r == n)
            {
                if (l == 1 && r == n)
                {
                    for (int i = 1; i <= n; ++i)
                    {
                        if (i % 2 == 0)
                            a[i] = 'R';
                        else
                            a[i] = 'B';
                    }
                }
                else if (r == n)
                {
                    for (int i = l; i <= r; ++i)
                    {
                        if (a[i - 1] == 'B')
                            a[i] = 'R';
                        else
                            a[i] = 'B';
                    }
                }
                else
                {
                    for (int i = r; i >= l; --i)
                    {
                        if (a[i + 1] == 'B')
                            a[i] = 'R';
                        else
                            a[i] = 'B';
                    }
                }
                continue;
            }
            for (int i = l; i <= r; ++i)
            {
                if (a[i - 1] == 'B')
                    a[i] = 'R';
                else
                    a[i] = 'B';
            }
            if (a[l - 1] == a[r + 1])
            {
                if ((r - l + 1) % 2 == 0)
                    ++ans;
            }
            else
            {
                if ((r - l + 1) % 2 == 1)
                    ++ans;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i];
    }
    cout << "\n";
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