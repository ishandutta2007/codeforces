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

    bool z = false;
    int u = 0;
    while (1)
    {
        int maxu = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == u)
                continue;
            maxu = max(maxu, a[i]);
        }
        if (maxu == 0)
        {
            z ^= true;
            if (z == false)
                cout << "T\n";
            else
                cout << "HL\n";
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == u)
                continue;
            if (a[i] == maxu)
            {
                --a[i];
                u = i;
                break;
            }
        }
        z ^= true;
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
        solv();
    return 0;
}