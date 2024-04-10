#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>

const int MAXN = 1009;
string a[MAXN][4];
int n;
bool u[MAXN];
string name[10 * MAXN];
int pt;

string gen(map<string, vector<pii> >& pos)
{
    while (pos.find(name[pt]) != pos.end())
    {
        pt++;
        if (pt >= 10 * MAXN)
            pt = 0;
    }
    return name[pt];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (char e0 = 'a'; e0 <= 'z'; e0++)
    {
        for (char e1 = 'a'; e1 <= 'z'; e1++)
        {
            for (char e2 = 'a'; e2 <= 'z'; e2++)
            {
                string u0 = "";
                u0 += e0;
                string u1 = "";
                u1 += e1;
                string u2 = "";
                u2 += e2;
                string cur = u0 + u1 + u2;
                name[pt] = cur;
                pt++;
                if (pt >= 10 * MAXN)
                    break;
            }
            if (pt >= 10 * MAXN)
                break;
        }
        if (pt >= 10 * MAXN)
                break;
    }
    pt = 0;
    cin >> n;
    set<char> xx;
    xx.insert('$');
    xx.insert('^');
    xx.insert('#');
    xx.insert('&');
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int e = 0;
        while (s[e] != '=')
        {
            a[i][0] += s[e];
            e++;
        }
        e++;
        while (e < (int)s.size() && (xx.find(s[e]) == xx.end()))
        {
            a[i][1] += s[e];
            e++;
        }
        if (e != (int)s.size())
        {
            a[i][2] += s[e];
            e++;
        }
        while (e < (int)s.size())
        {
            a[i][3] += s[e];
            e++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i][2].empty() && a[i][0] == a[i][1])
        {
            for (int e = i; e < n - 1; e++)
            {
                for (int j = 0; j < 4; j++)
                    a[e][j] = a[e + 1][j];
            }
            n--;
            i--;
        }
    }
    while (n > 0 && a[n - 1][0] != "res")
        n--;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    map<string, vector<pii> > pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!a[i][j].empty() && j != 2)
                pos[a[i][j]].pb(i, j);
        }
    }
    set<string> used;
    for (int i = 0; i < n - 1; i++)
    {
        used.insert(a[i][1]);
        if (!a[i][3].empty())
            used.insert(a[i][3]);
        if (used.find(a[i][0]) != used.end() || a[i][0] == "res")
        {
            string x = gen(pos);
            auto j = pos.find(a[i][0]);
            int m = (*j).ss.size();
            for (int e = 0; e < m; e++)
            {
                pii cur = ((*j).ss)[e];
                if ((cur.ff > i || (cur.ff == i && cur.ss == 0)) && !(cur.ff == n - 1 && cur.ss == 0))
                {
                    pos[x].pb(cur);
                    a[cur.ff][cur.ss] = x;
                    (*j).ss.erase((*j).ss.begin() + e);
                    e--;
                    m--;
                }
            }
        }
        used.insert(a[i][0]);
    }
    used.clear();
    for (int i = 0; i < n; i++)
        u[i] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (!u[i])
            continue;
        if (a[i][2].empty() && a[i][0] == a[i][1])
            u[i] = false;
        else if (a[i][2].empty())
        {
            string x1 = a[i][0];
            string x2 = a[i][1];
            auto j = pos.find(x1);
            int m = (*j).ss.size();
            for (int e = 0; e < m; e++)
            {
                pii cur = ((*j).ss)[e];
                if (cur.ff > i && u[cur.ff])
                {
                    pos[x2].pb(cur);
                    a[cur.ff][cur.ss] = x2;
                    (*j).ss.erase((*j).ss.begin() + e);
                    e--;
                    m--;
                }
            }
            u[i] = false;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (!u[i])
            continue;
        for (int e = 0; e < i; e++)
        {
            if (!u[e])
                continue;
            if (a[i][1] == a[e][1] && a[i][2] == a[e][2] && a[i][3] == a[e][3])
            {
                string x1 = a[i][0];
                string x2 = a[e][0];
                auto j = pos.find(x1);
                int m = (*j).ss.size();
                for (int e = 0; e < m; e++)
                {
                    pii cur = ((*j).ss)[e];
                    if (cur.ff > i && u[cur.ff])
                    {
                        pos[x2].pb(cur);
                        a[cur.ff][cur.ss] = x2;
                        (*j).ss.erase((*j).ss.begin() + e);
                        e--;
                        m--;
                    }
                }
                u[i] = false;
                break;
            }
        }
    }
    if (a[n - 1][2].empty())
    {
        string x = a[n - 1][1];
        auto j = pos.find(x);
        int m = (*j).ss.size();
        for (int e = 0; e < m; e++)
        {
            pii cur = ((*j).ss)[e];
            if (cur.ss == 0 && u[cur.ff])
            {
                a[n - 1][1] = a[cur.ff][1];
                a[n - 1][2] = a[cur.ff][2];
                a[n - 1][3] = a[cur.ff][3];
            }
        }
    }
    if (a[n - 1][2].empty() && a[n - 1][1] == "res")
    {
        cout << 0;
        return 0;
    }
    used.insert(a[n - 1][1]);
    used.insert(a[n - 1][3]);
    int cnt = 1;
    for (int e = n - 2; e >= 0; e--)
    {
        if (!u[e])
            continue;
        if (used.find(a[e][0]) == used.end())
            u[e] = false;
        else
        {
            cnt++;
            used.insert(a[e][1]);
            used.insert(a[e][3]);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        if (u[i])
            cout << a[i][0] << "=" << a[i][1] << a[i][2] << a[i][3] << "\n";
    }
}