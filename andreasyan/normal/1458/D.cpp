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
const int N = 1100006;

string dos(string s, int l, int r)
{
    string h = s;
    for (int i = l; i <= r; ++i)
    {
        if (s[l + (r - i)] == '0')
            h[i] = '1';
        else
            h[i] = '0';
    }
    return h;
}

string bfs(string s)
{
    string ans = s;

    set<string> c;
    queue<string> q;
    c.insert(s);
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        ans = min(ans, s);

        for (int l = 0; l < sz(s); ++l)
        {
            for (int r = l; r < sz(s); ++r)
            {
                int qq[2] = {};
                for (int i = l; i <= r; ++i)
                {
                    qq[s[i] - '0']++;
                }
                if (qq[0] == qq[1])
                {
                    string h = dos(s, l, r);
                    if (c.find(h) == c.end())
                    {
                        c.insert(h);
                        q.push(h);
                    }
                }
            }
        }
    }

    return ans;
}

string solv0(string s)
{
    for (int i = 0; i < sz(s); ++i)
    {
        if (s[i] == '0')
            continue;
        int qq = 0;
        for (int j = i; j < sz(s); ++j)
        {
            if (s[j] == '1')
                ++qq;
            else
                --qq;
            if (qq == 0 && s[j] == '1')
            {
                s = dos(s, i, j);
                break;
            }
        }
    }
    return s;
}

// this is wrong
string solv1(string s)
{
    int k = 0;
    for (int i = 0; i < sz(s); ++i)
    {
        k = max(k, i);
        if (s[i] == '0')
            continue;
        bool f = false;
        for (int j = k; j < sz(s); ++j)
        {
            int qq = 0;
            for (int u = i; u <= j; ++u)
            {
                if (s[u] == '0')
                    --qq;
                else
                    ++qq;
            }
            if (qq == 0 && s[j] == 1)
            {
                s = dos(s, i, j);
                k = j;
                f = true;
                break;
            }
        }
        if (!f)
            k = sz(s);
    }
}

int yy[N];
int yz;
struct ban
{
    char u;
    int y;
    int s;
    int q;
    bool laz;
    ban *l, *r;
    ban(){}
    ban(char u)
    {
        this->u = u;
        y = yy[yz++];
        if (u == '0')
            s = -1;
        else
            s = 1;
        q = 1;
        laz = false;
        l = r = 0;
    }
};
typedef ban* pban;

void chn(pban& t)
{
    if (t == 0)
        return;
    if (t->u == '0')
        t->u = '1';
    else
        t->u = '0';
    t->s *= (-1);
    t->laz ^= true;
    swap(t->l, t->r);
}

void shi(pban& t)
{
    if (t == 0)
        return;
    if (!t->laz)
        return;
    chn(t->l);
    chn(t->r);
    t->laz = false;
}

int gets(pban& t)
{
    if (t == 0)
        return 0;
    return t->s;
}

int getq(pban& t)
{
    if (t == 0)
        return 0;
    return t->q;
}

void ubd(pban& t)
{
    if (t == 0)
        return;
    t->s = gets(t->l) + gets(t->r);
    if (t->u == '0')
        --t->s;
    else
        ++t->s;
    t->q = getq(t->l) + 1 + getq(t->r);
}

void mer(pban l, pban r, pban& t)
{
    shi(l);
    shi(r);
    if (l == 0)
    {
        t = r;
        return;
    }
    if (r == 0)
    {
        t = l;
        return;
    }

    if (l->y > r->y)
    {
        mer(l->r, r, l->r);
        t = l;
    }
    else
    {
        mer(l, r->l, r->l);
        t = r;
    }
    ubd(t);
}

void spl(pban t, int x, pban& l, pban& r)
{
    shi(t);
    if (t == 0)
    {
        l = r = 0;
        return;
    }

    if (getq(t->l) >= x)
    {
        spl(t->l, x, l, t->l);
        r = t;
    }
    else
    {
        spl(t->r, x - getq(t->l) - 1, t->r, r);
        l = t;
    }
    ubd(l);
    ubd(r);
}

char getui(pban& t, int i)
{
    pban l, m, r;
    spl(t, i, l, m);
    spl(m, 1, m, r);
    char ans = m->u;
    mer(l, m, t);
    mer(t, r, t);
    return ans;
}

int q[N];

string solv(string s)
{
    int n = sz(s);
    int u = 500050;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            q[u]++;
            ++u;
        }
        else
        {
            --u;
            q[u]++;
        }
    }

    u = 500050;
    string ans = "";
    for (int i = 0; i < n; ++i)
    {
        if (q[u] > 1 || (q[u] == 1 && q[u - 1] == 0))
        {
            --q[u];
            ++u;
            ans += '0';
        }
        else
        {
            --u;
            --q[u];
            ans += '1';
        }
    }
    return ans;
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
        string s;
        cin >> s;
        cout << solv(s) << endl;
    }
    return 0;
    while (tt--)
    {
        string s = "";
        int n = rnf() % 20 + 1;
        for (int i = 0; i < n; ++i)
        {
            if (rnf() % 2 == 0)
                s += '0';
            else
                s += '1';
        }
        assert(bfs(s) == solv(s));
    }
    return 0;
}