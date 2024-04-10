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

int qq;
int q[N];
int s[N];
bool c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    qq = 0;
    for (int i = 0; i <= n + 1; ++i)
    {
        q[i] = 0;
        s[i] = 0;
        c[i] = false;
    }

    c[n] = c[n + 1] = true;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] <= a[i + 1] && c[i + 1])
            c[i] = true;
    }

    for (int i = 1; i <= n; ++i)
        ++s[a[i]];

    for (int i = 0; i <= n; ++i)
    {
        if (i)
        {
            ++q[a[i]];
            if (q[a[i]] == 1)
                ++qq;
            if (q[a[i]] == s[a[i]])
                --qq;
        }

        if (qq == 0 && c[i + 1])
        {
            set<int> t;
            for (int j = 1; j <= i; ++j)
                t.insert(a[j]);
            cout << sz(t) << "\n";
            return;
        }
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