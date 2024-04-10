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
const int N = 200005;

int n;
char a[N];

bool c[N][26];

void solv()
{
    cin >> a;
    n = strlen(a);

    for (int j = 0; j < 26; ++j)
    {
        c[n][j] = false;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            c[i][j] = c[i + 1][j];
        c[i][a[i] - 'a'] = true;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!c[i + 1][a[i] - 'a'])
        {
            for (int j = i; j < n; ++j)
                cout << a[j];
            cout << "\n";
            return;
        }
    }
    assert(false);
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