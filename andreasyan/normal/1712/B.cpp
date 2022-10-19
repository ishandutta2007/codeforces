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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

void solv()
{
    int n;
    cin >> n;

    /*vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    ll ans = 0;
    vector<int> vans;
    do
    {
        ll yans = 0;
        for (int i = 0; i < n; ++i)
            yans += ((i + 1) * 1LL * v[i] / gcd(i + 1, v[i]));
        if (yans > ans)
        {
            ans = yans;
            vans = v;
        }
    } while (next_permutation(all(v)));

    for (int i = 0; i < n; ++i)
        cout << vans[i] << ' ';
    cout << "\n";*/

    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << "\n";
    }
    else
    {
        cout << "1 ";
        for (int i = 2; i <= n; i += 2)
        {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << "\n";
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