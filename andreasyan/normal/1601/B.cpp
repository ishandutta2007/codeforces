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
const int N = 300005;

int n;
int a[N], b[N];

int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    set<int> s;
    for (int i = 0; i <= n; ++i)
        s.insert(i);

    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        int sx = x;

        x += b[x];

        if (x == 0)
        {
            vector<int> ans;
            while (x != n)
            {
                ans.push_back(x);
                x = p[x];
            }
            reverse(all(ans));

            cout << sz(ans) << "\n";
            for (int i = 0; i < sz(ans); ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            return;
        }

        int l = x - a[x];
        while (1)
        {
            auto it = s.lower_bound(l);
            if (it == s.end())
                break;
            if (*it > x)
                break;
            p[*it] = sx;
            q.push(*it);
            s.erase(it);
        }
    }

    cout << "-1\n";
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