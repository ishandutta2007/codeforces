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
bool c[N];

void solv()
{
    cin >> n;

    c[0] = c[1] = true;
    for (int i = 2; i <= n + 1; ++i)
    {
        if (c[i])
            continue;
        for (int j = i + i; j <= n + 1; j += i)
            c[j] = true;
    }

    if (n <= 2)
        cout << "1\n";
    else
        cout << "2\n";
    for (int i = 2; i <= n + 1; ++i)
    {
        if (c[i])
            cout << "2 ";
        else
            cout << "1 ";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}