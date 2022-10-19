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
char s[N][5];

bool c2[26][26], c32[26][26];
bool c3[26][26][26];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    memset(c2, false, sizeof c2);
    memset(c32, false, sizeof c32);
    memset(c3, false, sizeof c3);

    for (int i = 1; i <= n; ++i)
    {
        int m = strlen(s[i]);
        bool z = true;
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] != s[i][m - j - 1])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            cout << "YES\n";
            return;
        }

        if (m == 2)
        {
            if (c2[s[i][1] - 'a'][s[i][0] - 'a'])
            {
                cout << "YES\n";
                return;
            }
            if (c32[s[i][1] - 'a'][s[i][0] - 'a'])
            {
                cout << "YES\n";
                return;
            }
            c2[s[i][0] - 'a'][s[i][1] - 'a'] = true;
        }
        else
        {
            if (c3[s[i][2] - 'a'][s[i][1] - 'a'][s[i][0] - 'a'])
            {
                cout << "YES\n";
                return;
            }
            if (c2[s[i][2] - 'a'][s[i][1] - 'a'])
            {
                cout << "YES\n";
                return;
            }
            c3[s[i][0] - 'a'][s[i][1] - 'a'][s[i][2] - 'a'] = true;
            c32[s[i][0] - 'a'][s[i][1] - 'a'] = true;
        }
    }

    cout << "NO\n";
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