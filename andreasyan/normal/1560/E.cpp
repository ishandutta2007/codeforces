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
const int N = 500005;

int n;
char a[N];

void solv()
{
    cin >> a;
    n = strlen(a);

    bool c[26] = {};
    int q[26] = {};
    int s[26] = {};

    vector<char> v;

    set<char> tt;
    for (int i = 0; i < n; ++i)
        tt.insert(a[i]);
    int ii = sz(tt);

    while (1)
    {
        char x = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (!c[a[i] - 'a'])
            {
                x = a[i];
                break;
            }
        }
        if (x == 0)
            break;

        v.push_back(x);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == x)
                ++q[x - 'a'];
        }
        c[x - 'a'] = true;

        if (q[x - 'a'] % ii != 0)
        {
            cout << "-1\n";
            return;
        }
        s[x - 'a'] = q[x - 'a'] / ii;
        --ii;
    }
    reverse(all(v));

    int ss = 0;
    for (int i = 0; i < 26; ++i)
        ss += s[i];

    int stgs[26] = {};
    for (int i = 0; i < ss; ++i)
    {
        ++stgs[a[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (s[i] != stgs[i])
        {
            cout << "-1\n";
            return;
        }
    }

    memset(c, false, sizeof c);
    int css = ss;
    int j = ss;
    for (int i = 0; i < sz(v); ++i)
    {
        ss -= s[v[i] - 'a'];
        c[v[i] - 'a'] = true;

        vector<char> b;
        for (int i = 0; i < css; ++i)
        {
            if (c[a[i] - 'a'])
                continue;
            b.push_back(a[i]);
        }

        for (int k = 0; k < ss; ++k)
        {
            if (j == n)
            {
                cout << "-1\n";
                return;
            }
            if (a[j++] != b[k])
            {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 0; i < css; ++i)
        cout << a[i];
    cout << ' ';
    for (int i = 0; i < sz(v); ++i)
        cout << v[i];
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