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
const int N = 1003;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    bool s = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i + 1] < a[i])
        {
            s = false;
            break;
        }
    }

    if (s)
    {
        cout << "0\n";
        return;
    }

    int l = 1, r = n;
    vector<int> ans;
    while (l <= r)
    {
        int u1 = N;
        for (int i = l; i <= r; ++i)
        {
            if (a[i] == '1')
            {
                u1 = i;
                break;
            }
        }
        int u0 = -N;
        for (int i = r; i >= l; --i)
        {
            if (a[i] == '0')
            {
                u0 = i;
                break;
            }
        }

        if (u0 < u1)
        {
            break;
        }

        ans.push_back(u0);
        ans.push_back(u1);

        l = u1 + 1;
        r = u0 - 1;
    }

    sort(all(ans));
    cout << "1\n";
    cout << sz(ans) << ' ';
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
    {
        solv();
    }
    return 0;
}