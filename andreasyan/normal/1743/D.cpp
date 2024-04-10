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
const int N = 1000006;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;

    int s = n;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
        {
            s = i;
            break;
        }
    }

    if (s == n)
    {
        cout << "0\n";
        return;
    }

    int z = n;
    for (int i = s; i < n; ++i)
    {
        if (a[i] == '0')
        {
            z = i;
            break;
        }
    }

    if (z == n)
    {
        for (int i = s; i < n; ++i)
            cout << '1';
        cout << "\n";
        return;
    }

    string ans = "";
    for (int i = s; i < n; ++i)
        ans += a[i];

    for (int l = s; l < z; ++l)
    {
        string yans = "";
        int r = l + (n - z) - 1;
        for (int i = n - 1, j = r; j >= l; --i, --j)
        {
            if (a[i] == '1' || a[j] == '1')
                yans += '1';
            else
                yans += '0';
        }
        for (int i = s; i < z; ++i)
            yans += '1';
        reverse(all(yans));

        for (int i = 0; i < n - s; ++i)
        {
            if (ans[i] != yans[i])
            {
                if (yans[i] > ans[i])
                {
                    ans = yans;
                }
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}