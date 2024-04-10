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
int a[N];

int ans[N];
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    map<int, int> q;
    for (int i = 1; i <= n; ++i)
        q[a[i]]++;

    for (auto it = q.begin(); it != q.end(); ++it)
    {
        if (it->se > n / 2)
        {
            cout << "NO\n";
            return;
        }
        else if (it->se == n / 2)
        {
            vector<int> v;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] != it->fi)
                    v.push_back(a[i]);
            }
            assert(sz(v) == n / 2);
            for (int i = 1; i <= n; ++i)
            {
                if (i % 2 == 0)
                    ans[i] = it->fi;
                else
                    ans[i] = v[i / 2];
            }
            ans[0] = ans[n];
            ans[n + 1] = ans[1];

            bool z = true;
            for (int i = 1; i <= n; ++i)
            {
                if (!((ans[i - 1] < ans[i] && ans[i] > ans[i + 1]) || (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])))
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                cout << "YES\n";
                for (int i = 1; i <= n; ++i)
                    cout << ans[i] << ' ';
                cout << "\n";
            }
            else
            {
                cout << "NO\n";
            }
            return;
        }
    }

    sort(a + 1, a + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i += 2)
        ans[i] = a[j++];
    for (int i = 2; i <= n; i += 2)
        ans[i] = a[j++];

    ans[0] = ans[n];
    ans[n + 1] = ans[1];
    for (int i = 1; i <= n; ++i)
    {
        assert(((ans[i - 1] < ans[i] && ans[i] > ans[i + 1]) || (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])));
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";

    sort(ans + 1, ans + n + 1);
    for (int i = 1; i <= n; ++i)
        assert(ans[i] == a[i]);
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