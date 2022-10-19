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
const ll INF = 1000000009000000009;

int n;
char a[N], b[N];

stack<int> s[26];

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

void solv()
{
    cin >> n;
    cin >> (a + 1) >> (b + 1);

    for (int i = 0; i < 26; ++i)
    {
        while (!s[i].empty())
            s[i].pop();
    }
    for (int i = 1; i <= n; ++i)
        t[i] = 0;

    for (int i = n; i >= 1; --i)
    {
        s[a[i] - 'a'].push(i);
    }

    ll ans = INF;
    ll yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < b[i] - 'a'; ++j)
        {
            if (!s[j].empty())
                ans = min(ans, yans + s[j].top() - i + qry(n) - qry(s[j].top()));
        }
        if (s[b[i] - 'a'].empty())
            break;
        yans += s[b[i] - 'a'].top() - i;
        yans += qry(n) - qry(s[b[i] - 'a'].top());
        ubd(s[b[i] - 'a'].top());
        s[b[i] - 'a'].pop();
    }

    if (ans == INF)
        cout << "-1\n";
    else
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}