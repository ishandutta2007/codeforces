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

bool gort(char x)
{
    return (x == '$' || x == '^' || x == '#' || x == '&');
}

void solv()
{
    vector<string> a;
    int qq;
    cin >> qq;
    while (qq--)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }

    set<string> f;
    f.insert("res");

    vector<string> u;
    vector<pair<char, pair<string, string> > > b;
    set<string> ab;
    for (int i = sz(a) - 1; i >= 0; --i)
    {
        string s = "";
        int j;
        for (j = 0; j < sz(a[i]); ++j)
        {
            if (a[i][j] == '=')
                break;
            s += a[i][j];
        }
        if (f.find(s) == f.end())
            continue;
        f.erase(s);
        u.push_back(s);

        b.push_back(m_p(0, m_p("", "")));
        for (j = j + 1; j < sz(a[i]); ++j)
        {
            if (gort(a[i][j]))
            {
                b.back().fi = a[i][j];
            }
            else
            {
                if (!b.back().fi)
                    b.back().se.fi += a[i][j];
                else
                    b.back().se.se += a[i][j];
            }
        }
        if (b.back().fi)
        {
            f.insert(b.back().se.fi);
            f.insert(b.back().se.se);
        }
        else
            f.insert(b.back().se.fi);

        ab.insert(s);
        ab.insert(b.back().se.fi);
        if (b.back().fi)
            ab.insert(b.back().se.se);
    }
    reverse(all(u));
    reverse(all(b));

    map<string, string> mp;
    map<string, string> rmp;
    for (auto it = f.begin(); it != f.end(); ++it)
    {
        mp[*it] = *it;
        rmp[*it] = *it;
    }

    int z = 0;
    vector<string> t;
    for (char t1 = 'a'; t1 <= 'z'; ++t1)
    {
        for (char t2 = 'a'; t2 <= 'z'; ++t2)
        {
            for (char t3 = 'a'; t3 <= 'z'; ++t3)
            {
                string s = "";
                s += t1;
                s += t2;
                s += t3;

                if (ab.find(s) != ab.end())
                    continue;
                t.push_back(s);
            }
        }
    }

    vector<string> ans;
    for (int i = 0; i < sz(b); ++i)
    {
        string g = rmp[b[i].se.fi];
        if (b[i].fi)
        {
            g += b[i].fi;
            g += rmp[b[i].se.se];
        }

        if (mp.find(g) == mp.end())
        {
            if (!b[i].fi)
            {
                while (1){}
            }
            mp[g] = t[z];

            f.insert(t[z]);
            mp[t[z]] = t[z];

            string s = t[z];
            s += '=';
            s += g;
            ans.push_back(s);
            ++z;
        }
        if (i == sz(b) - 1)
        {
            if (ans.empty())
            {
                if (g == "res")
                    break;
                string s = "res=" + g;
                ans.push_back(s);
                break;
            }
            string s = "";
            int j;
            for (j = 0; j < sz(ans.back()); ++j)
            {
                if (ans.back()[j] == '=')
                    break;
                s += ans.back()[j];
            }

            if (s != mp[g])
            {
                while (1){}
            }

            s = u[i];
            for (; j < sz(ans.back()); ++j)
                s += ans.back()[j];
            ans.pop_back();
            ans.push_back(s);
            break;
        }

        rmp[u[i]] = mp[g];
        /*for (int j = i + 1; j < sz(b); ++j)
        {
            if (b[j].se.fi == u[i])
                b[j].se.fi = mp[g];
            if (b[j].se.se == u[i])
                b[j].se.se = mp[g];
            if (u[j] == u[i])
                break;
        }*/
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << "\n";
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