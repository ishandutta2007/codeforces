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
string a[N];

struct ban
{
    string bacpak, gbac, gpak;
    ban(){}
    ban(string s)
    {
        if (s == "lock" || s == "unlock")
        {
            bacpak = s;
            gbac = "-1";
            gpak = "-1";
        }
        else
        {
            bacpak = "-1";
            gbac = s;
            gpak = "-1";
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban ans;
    if (r.bacpak == "-1")
        ans.bacpak = l.bacpak;
    else
        ans.bacpak = r.bacpak;

    ans.gbac = l.gbac;
    string s = l.bacpak;
    if (s == "-1")
        s = "unlcok";
    if (s == "lock")
    {
        if (r.gpak != "-1")
            ans.gbac = r.gpak;
    }
    else
    {
        if (r.gbac != "-1")
            ans.gbac = r.gbac;
    }

    ans.gpak = l.gpak;
    s = l.bacpak;
    if (s == "-1")
        s = "lock";
    if (s == "lock")
    {
        if (r.gpak != "-1")
            ans.gpak = r.gpak;
    }
    else
    {
        if (r.gbac != "-1")
            ans.gpak = r.gbac;
    }

    return ans;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, string y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);

    int qq;
    cin >> qq;
    if (t[1].gbac != "-1")
        cout << t[1].gbac << "\n";
    else
        cout << "blue\n";
    while (qq--)
    {
        int x;
        string y;
        cin >> x >> y;
        ubd(1, n, x, y, 1);
        if (t[1].gbac != "-1")
            cout << t[1].gbac << "\n";
        else
            cout << "blue\n";
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