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

int n, k;
char a[N];

void solv()
{
    cin >> n >> k;
    cin >> a;

    int l, r;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
        {
            if (q == 0)
                l = i;
            r = i;
            ++q;
        }
    }

    if (q == 0)
    {
        cout << "0\n";
        return;
    }
    if (q == 1)
    {
        if ((n - r - 1) <= k)
            cout << "1\n";
        else if (l <= k)
            cout << "10\n";
        else
            cout << "11\n";
        return;
    }

    if ((n - r - 1) + l <= k)
        cout << (q - 1) * 11 << "\n";
    else if ((n - r - 1) <= k)
        cout << q * 11 - 10 << "\n";
    else if (l <= k)
        cout << q * 11 - 1 << "\n";
    else
        cout << q * 11 << "\n";
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