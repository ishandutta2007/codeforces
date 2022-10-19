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
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int q = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
            ++q;
    }

    if (q <= 1)
    {
        cout << "0\n";
        return;
    }

    int l = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            l = i;
            break;
        }
    }
    assert(l);

    int r = 0;
    for (int i = n; i > 1; --i)
    {
        if (a[i] == a[i - 1])
        {
            r = i;
            break;
        }
    }
    assert(r);

    if (r - l + 1 == 3)
    {
        cout << "1\n";
    }
    else
    {
        cout << r - l - 2 << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}