#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003, INF = 2000000009;
struct ban
{
    int x, i;
    ban(){}
    ban(int x, int i)
    {
        this->x = x;
        this->i = i;
    }
};

int n, m;
int s, f;
pair<pair<int, int>, int> b[N * 30];
vector<ban> a[N];

int hi;

bool c[N];
int pi[N], px[N];
bool dfs0(int x)
{
    c[x] = true;
    if (x == f)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (a[x][i].i == hi)
            continue;
        if (!c[h])
        {
            pi[h] = a[x][i].i;
            px[h] = x;
            if (dfs0(h))
                return true;
        }
    }
    return false;
}

vector<int> path()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    dfs0(s);
    vector<int> v;
    if (!c[f])
        return v;
    for (int i = f; i != s; i = px[i])
    {
        v.push_back(pi[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> vv;
int tin[N], ti, fup[N];
void dfs(int x, int pi)
{
    c[x] = true;
    tin[x] = ti++;
    fup[x] = tin[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (a[x][i].i == pi)
            continue;
        if (a[x][i].i == hi)
            continue;
        if (!c[h])
        {
            dfs(h, a[x][i].i);
            fup[x] = min(fup[x], fup[h]);
            if (fup[h] > tin[x])
                vv.push_back(a[x][i].i);
        }
        else
        {
            fup[x] = min(fup[x], tin[h]);
        }
    }
}

vector<int> bridges()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    vv.clear();
    dfs(s, 0);
    return vv;
}

int ans = INF;
int anss;
int ans1, ans2;

int main()
{
    cin >> n >> m;
    cin >> s >> f;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(ban(y, i));
        a[y].push_back(ban(x, i));
        b[i] = m_p(m_p(x, y), z);
    }

    if (s == f)
    {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> somepath = path();
    if (somepath.empty())
    {
        cout << 0 << endl << 0 << endl;
        return 0;
    }

    for (int i = 0; i < somepath.size(); ++i)
    {
        hi = somepath[i];
        vector<int> p = path();
        if (p.empty())
        {
            if (b[somepath[i]].second < ans)
            {
                ans = b[somepath[i]].second;
                anss = 1;
                ans1 = somepath[i];
            }
            continue;
        }
        set<int> s;
        for (int j = 0; j < p.size(); ++j)
            s.insert(p[j]);
        if (hi == 2)
            cerr << "";
        vector<int> br = bridges();
        /*if (hi == 2)
        {
            cerr << endl;
            for (int j = 0; j < p.size(); ++j)
                cerr << p[j] << ' ';
            cerr << endl << endl;
        }*/
        for (int j = 0; j < br.size(); ++j)
        {
            if (s.find(br[j]) != s.end())
            {
                if (b[somepath[i]].second + b[br[j]].second < ans)
                {
                    ans = b[somepath[i]].second + b[br[j]].second;
                    anss = 2;
                    ans1 = somepath[i];
                    ans2 = br[j];
                }
            }
        }
    }

    if (ans == INF)
    {
        cout << "-1" << endl;
        return 0;
    }

    cout << ans << endl;
    cout << anss << endl;
    if (anss == 1)
        cout << ans1 << endl;
    else
        cout << ans1 << ' ' << ans2 << endl;
    return 0;
}