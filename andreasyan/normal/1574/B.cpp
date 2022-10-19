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
    ll a[3], m;

    cin >> a[0] >> a[1] >> a[2] >> m;

    sort(a, a + 3);
    ll maxu = a[0] - 1 + a[1] - 1 + a[2] - 1;

    ll minu = 0;
    if (a[2] > a[0] + a[1])
        minu = a[2] - a[0] - a[1] - 1;

    if (minu <= m && m <= maxu)
        cout << "YES\n";
    else
        cout << "NO\n";
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
        solv();
    return 0;
}