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
const int N = 19;

struct ban
{
    ll l, r, s, ans;
    ban()
    {
        l = r = s = ans = 0;
    }
    ban(int x)
    {
        s = x;
        if (x >= 0)
            l = r = ans = x;
        else
            l = r = ans = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.l = max(l.l, l.s + r.l);
    res.r = max(r.r, r.s + l.r);
    res.ans = max(l.ans, r.ans);
    res.ans = max(res.ans, l.r + r.l);
    return res;
}

int n;
int a[(1 << N)];

vector<ban> bil(int tl, int tr)
{
    vector<ban> ans;
    if (tl == tr)
    {
        ans.push_back(ban(a[tl]));
        return ans;
    }
    int m = (tl + tr) / 2;
    vector<ban> l = bil(tl, m);
    vector<ban> r = bil(m + 1, tr);
    for (int i = 0; i < sz(l); ++i)
        ans.push_back(mer(l[i], r[i]));
    for (int i = 0; i < sz(l); ++i)
        ans.push_back(mer(r[i], l[i]));
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= (1 << n); ++i)
        cin >> a[i];

    vector<ban> ans = bil(1, (1 << n));
    int x = 0;
    int qq;
    cin >> qq;
    while (qq--)
    {
        int i;
        cin >> i;
        x ^= (1 << i);
        cout << ans[x].ans << "\n";
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