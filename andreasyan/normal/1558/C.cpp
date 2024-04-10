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
const int N = 2106;

int n;
int a[N];

vector<int> ans;
void ubd(int x)
{
    assert(x % 2 == 1);
    ans.push_back(x);
    reverse(a + 1, a + x + 1);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        if ((a[i] % 2) != (i % 2))
        {
            cout << "-1\n";
            return;
        }
    }

    ans.clear();

    for (int i = n; i > 1; i -= 2)
    {
        int u9, u8;
        for (int j = 1; j <= i; ++j)
        {
            if (a[j] == i)
            {
                u9 = j;
            }
            else if (a[j] == i - 1)
            {
                u8 = j;
            }
        }

        if (u8 < u9)
        {
            if (u8 == u9 - 1)
            {
                ubd(u9);
            }
            else
            {
                ubd(u9);
                u8 = (u9 - u8 + 1);
                ubd(u8 - 1);
                ubd(u8 + 1);
                ubd(3);
            }
        }
        else
        {
            if (u9 == u8 - 1)
            {
                ubd(u8 + 1);
                ubd(3);
            }
            else
            {
                ubd(u9);
                ubd(u8 - 1);
                ubd(u8 + 1);
                ubd(3);
            }
        }
        ubd(i);
    }

    for (int i = 1; i <= n; ++i)
        assert(a[i] == i);

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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
        solv();
    return 0;
}