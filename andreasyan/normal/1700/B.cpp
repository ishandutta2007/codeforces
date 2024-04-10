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
char a[N];

char b[N];

void solv()
{
    cin >> n;
    cin >> a;

    b[n] = 0;

    if (a[0] < '9')
    {
        for (int i = 0; i < n; ++i)
            b[i] = '9' - a[i] + '0';
    }
    else
    {
        int m = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int x = a[i] - '0' + m;
            x = 1 - x;

            if (x < 0)
            {
                x += 10;
                m = 1;
            }
            else
                m = 0;

            b[i] = x + '0';
        }
    }

    cout << b << "\n";
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