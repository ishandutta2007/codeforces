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

void solv()
{
    int n;
    string s;
    cin >> s;
    n = sz(s);

    if (s[0] == 'A' && s[n - 1] == 'B')
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'B')
            {
                if (q == 0)
                {
                    cout << "NO\n";
                    return;
                }
                --q;
            }
            else
            {
                ++q;
            }
        }
        cout << "YES\n";
    }
    else
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