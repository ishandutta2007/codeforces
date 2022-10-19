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
const int N = 102;

int n, a, b;
char s[N];

void solv()
{
    cin >> n >> a >> b;
    cin >> (s + 1);

    if (b >= 0)
        cout << a * n + b * n << "\n";
    else
    {
        int q = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i] != s[i - 1])
            {
                ++q;
            }
        }
        cout << (q / 2 + 1) * b + a * n << "\n";
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