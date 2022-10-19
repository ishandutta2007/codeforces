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
const int N = 300005;

int p[N];

int a, b;

void solv()
{
    cin >> a >> b;
    if (p[a - 1] == b)
        cout << a << "\n";
    else
    {
        int u = (p[a - 1] ^ b);
        if (u != a)
            cout << a + 1 << "\n";
        else
            cout << a + 2 << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    for (int i = 1; i < N; ++i)
        p[i] = (p[i - 1] ^ i);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}