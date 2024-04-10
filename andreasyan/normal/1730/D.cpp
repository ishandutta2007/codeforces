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
char a[N], b[N];

int q[26][26];
void solv()
{
    cin >> n;
    cin >> a >> b;

    memset(q, 0, sizeof q);
    for (int i = 0; i < n; ++i)
    {
        q[min(a[i], b[n - i - 1]) - 'a'][max(a[i], b[n - i - 1]) - 'a']++;
    }

    if (n % 2 == 1)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (q[i][i] && q[i][i] % 2 == 1)
            {
                --q[i][i];
                break;
            }
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        for (int j = i; j < 26; ++j)
        {
            if (q[i][j] % 2 == 1)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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