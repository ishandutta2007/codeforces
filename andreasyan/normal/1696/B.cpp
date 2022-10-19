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
const int N = 100005;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            ++q;
    }

    if (q == n)
    {
        cout << "0\n";
        return;
    }

    int l;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
        {
            l = i;
            break;
        }
    }
    int r;
    for (int i = n; i >= 1; --i)
    {
        if (a[i])
        {
            r = i;
            break;
        }
    }

    if ((r - l + 1) == n - q)
        cout << "1\n";
    else
        cout << "2\n";
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