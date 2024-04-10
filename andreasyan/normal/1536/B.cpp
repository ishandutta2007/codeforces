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

int d;
char b[10];
bool rec(int i)
{
    if (i == d + 1)
    {
        bool z = true;
        for (int j = 1; j <= n - d + 1; ++j)
        {
            bool zz = true;
            for (int k = j; k < j + d; ++k)
            {
                if (a[k] != b[k - j + 1])
                {
                    zz = false;
                    break;
                }
            }
            if (zz)
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            for (int j = 1; j <= d; ++j)
                cout << b[j];
            cout << "\n";
            return true;
        }
        return false;
    }
    for (char j = 'a'; j <= 'z'; ++j)
    {
        b[i] = j;
        if (rec(i + 1))
            return true;
    }
    return false;
}

void solv()
{
    cin >> n;
    cin >> (a + 1);

    for (d = 1; d <= 3; ++d)
    {
        if (rec(1))
            break;
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