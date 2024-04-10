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

int n, m;
char s[N], t[N];

void solv()
{
    cin >> s >> t;
    n = strlen(s);
    m = strlen(t);

    reverse(s, s + n);
    reverse(t, t + m);

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (j == m)
            break;
        if (s[i] == t[j])
        {
            ++j;
        }
        else
        {
            ++i;
        }
    }

    if (j == m)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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