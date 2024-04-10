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
const int N = 200005;

int n;
char a[N];

int p[N];
void bil()
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '(')
            ++p[i];
        else
            --p[i];
    }
    p[n + 1] = 0;
}
bool stg()
{
    bool z = true;
    for (int i = 0; i <= n; ++i)
    {
        if (p[i] < 0)
        {
            z = false;
            break;
        }
    }
    return z;
}

void solv()
{
    cin >> n;
    cin >> (a + 1);
    n *= 2;

    bil();
    if (stg())
    {
        cout << "0\n";
        return;
    }

    int maxl = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (p[i] < 0)
        {
            break;
        }
        if (p[i] > p[maxl])
            maxl = i;
    }

    int maxr = n;
    for (int i = n; i >= 0; --i)
    {
        if (p[i] < 0)
        {
            break;
        }
        if (p[i] > p[maxr])
            maxr = i;
    }

    reverse(a + maxl + 1, a + maxr + 1);
    bil();
    if (stg())
    {
        cout << "1\n";
        cout << maxl + 1 << ' ' << maxr << "\n";
        return;
    }

    reverse(a + maxl + 1, a + maxr + 1);
    bil();
    int maxi = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (p[i] > p[maxi])
            maxi = i;
    }

    cout << "2\n";
    cout << "1 " << maxi << "\n";
    cout << maxi + 1 << ' ' << n << "\n";
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