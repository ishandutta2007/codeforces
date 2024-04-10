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
const int N = 1003;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;

    int q00 = 0;
    int q01 = 0;
    int q0 = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        if (a[i] == '0' && a[n - i - 1] == '0')
            ++q00;
        if (a[i] != a[n - i - 1])
            ++q01;
    }
    if (n % 2 == 1 && a[n / 2] == '0')
        ++q0;

    if (q01 == 0)
    {
        if (q00 == 0)
        {
            cout << "BOB\n";
        }
        else if (q0 == 0)
        {
            cout << "BOB\n";
        }
        else
        {
            cout << "ALICE\n";
        }
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