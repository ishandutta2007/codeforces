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
const int N = 3000006, M = 998244353;

vector<int> v;
char f(int i, int x)
{
    if (x <= 1)
        return '0' + x;
    if (x == 2)
        return '0' + 1 - i;
    if (i < v[x - 1])
        return f(i, x - 1);
    else
        return f(i - v[x - 1], x - 2);
}

int m;
char aa[1003];
int n;
char a[N];

void solv()
{
    v.push_back(1);
    v.push_back(1);
    while (v.back() < N)
        v.push_back(v[sz(v) - 2] + v.back());

    vector<int> s;
    int qq;
    cin >> qq;
    while (qq--)
    {
        cin >> aa;
        m = strlen(aa);
        s.push_back(m);
        for (int i = 0; i < m; ++i)
            a[n++] = aa[i];
    }
    for (int i = 1; i < sz(s); ++i)
        s[i] += s[i - 1];
    reverse(all(s));

    vector<pair<int, int> > h;
    int yans = 0;
    for (int i = 0; i <= n; ++i)
    {
        int dp = yans;
        vector<pair<int, int> > nh;
        for (int j = 0; j < sz(h); ++j)
        {
            if (h[j].fi == i)
            {
                dp = (dp - h[j].se + M) % M;
            }
            else
            {
                nh.push_back(h[j]);
            }
        }
        swap(h, nh);
        if (i == 0)
            dp = 1;

        yans = (yans + dp) % M;

        if (i < n)
        {
            if (a[i] == '0')
                h.push_back(m_p(i + 1, dp));
            int k = 1;
            for (int j = i; j < n; ++j)
            {
                if (a[j] != f(j - i, sz(v) - 1))
                    break;
                if (j - i + 1 == v[k])
                {
                    h.push_back(m_p(j + 1, dp));
                    ++k;
                }
            }
        }

        if (i == s.back())
        {
            s.pop_back();
            cout << dp << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}