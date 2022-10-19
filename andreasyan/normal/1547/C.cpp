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
const int N = 103;

int k, n, m;
int a[N], b[N];

void solv()
{
    cin >> k >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    int i = 1, j = 1;
    vector<int> ans;
    while (1)
    {
        if (i == n + 1 && j == m + 1)
            break;
        if (i == n + 1)
        {
            ans.push_back(b[j]);
            if (b[j] == 0)
            {
                ++j;
                ++k;
                continue;
            }
            if (b[j] > k)
            {
                cout << "-1\n";
                return;
            }
            ++j;
            continue;
        }
        if (j == m + 1)
        {
            ans.push_back(a[i]);
            if (a[i] == 0)
            {
                ++i;
                ++k;
                continue;
            }
            if (a[i] > k)
            {
                cout << "-1\n";
                return;
            }
            ++i;
            continue;
        }
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            if (a[i] == 0)
            {
                ++i;
                ++k;
                continue;
            }
            if (a[i] > k)
            {
                cout << "-1\n";
                return;
            }
            ++i;
        }
        else
        {
            ans.push_back(b[j]);
            if (b[j] == 0)
            {
                ++j;
                ++k;
                continue;
            }
            if (b[j] > k)
            {
                cout << "-1\n";
                return;
            }
            ++j;
        }
    }

    for (int i = 0; i < n + m; ++i)
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