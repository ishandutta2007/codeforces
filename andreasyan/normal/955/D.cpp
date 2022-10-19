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

int n, m, k;
char a[N];
char b[N];

int ss;
char s[N];
int z[N];
void clcz()
{
    int r = 0, j;
    for (int i = 1; i < ss; ++i)
    {
        z[i] = 0;
        if (i <= r)
            z[i] = min(r - i + 1, z[i - j]);
        while (s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
}

int q1[N], q2[N];

vector<int> v[N];

int ans1[N], ans2[N];

void solv()
{
    cin >> n >> m >> k;
    cin >> a >> b;

    ss = 0;
    for (int i = 0; i < m; ++i)
        s[ss++] = b[i];
    for (int i = 0; i < n; ++i)
        s[ss++] = a[i];
    clcz();
    for (int i = m; i < n + m; ++i)
        q1[i - m] = min(z[i], m);

    ss = 0;
    for (int i = m - 1; i >= 0; --i)
        s[ss++] = b[i];
    for (int i = n - 1; i >= 0; --i)
        s[ss++] = a[i];
    clcz();
    for (int i = m; i < n + m; ++i)
        q2[n - (i - m) - 1] = min(z[i], m);

    /*for (int i = 0; i < n; ++i)
        cout << q1[i] << ' ';
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << q2[i] << ' ';
    cout << "\n";*/

    for (int i = 0; i < n; ++i)
    {
        if (q1[i] == m)
        {
            int u = 0;
            if (i + m - 1 - 2 * k + 1 >= 0)
                u = i + m - 1 - 2 * k + 1;
            cout << "Yes\n";
            cout << u +(1) << ' ' << u + k +(1) << "\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i)
        v[q1[i]].push_back(i);
    set<int> s;
    for (int i = k; i < n; ++i)
        s.insert(i);

    for (int s1 = 1; s1 < m; ++s1)
    {
        if (s1 > k)
            break;
        int i = k - s1;
        if (q1[i] >= s1)
        {
            v[q1[i]].push_back(i);
            s.insert(i);
        }
        while (!v[s1 - 1].empty())
        {
            s.erase(v[s1 - 1].back());
            v[s1 - 1].pop_back();
        }
        ans1[s1] = N;
        if (!s.empty())
            ans1[s1] = *s.begin();
    }

    for (int i = 0; i <= m; ++i)
        v[i].clear();
    for (int i = 0; i < n; ++i)
        v[q2[i]].push_back(i);
    s.clear();
    for (int i = 0; i <= n - k - 1; ++i)
        s.insert(i);
    for (int s2 = 1; s2 < m; ++s2)
    {
        if (s2 > k)
            break;
        int i = n - 1 - (k - s2);
        if (q2[i] >= s2)
        {
            v[q2[i]].push_back(i);
            s.insert(i);
        }
        while (!v[s2 - 1].empty())
        {
            s.erase(v[s2 - 1].back());
            v[s2 - 1].pop_back();
        }
        ans2[s2] = -N;
        if (!s.empty())
            ans2[s2] = *(--s.end());
    }

    for (int s1 = 1; s1 < m; ++s1)
    {
        int s2 = m - s1;
        if (s1 > k || s2 > k)
            continue;
        if (ans1[s1] + s1 - 1 < ans2[s2] - s2 + 1)
        {
            cout << "Yes\n";
            cout << ans1[s1] + s1 - 1 - k + 1 +(1) << ' ' << ans2[s2] - s2 + 1 +(1) << "\n";
            return;
        }
    }
    cout << "No\n";
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