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
const int N = 200005;
struct ban0
{
    int x, d, t, p;
};

int n, L;
ban0 a[N];

struct ban
{
    int x, d;
    int p;
    bool ogt;
    ban(){}
    ban(int x, int d, int p, bool ogt)
    {
        this->x = x;
        this->d = d;
        this->p = p;
        this->ogt = ogt;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

vector<pair<int, int> > v;

bool c[N];
int p[N];
bool ogt[N];
int djk()
{
    priority_queue<ban> q;
    q.push(ban(0, 0, 0, false));
    while (!q.empty())
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        p[t.x] = t.p;
        ogt[t.x] = t.ogt;
        if (t.x == sz(v) - 1)
        {
            return t.d;
        }
        if (t.x > 0)
        {
            ban h = t;
            h.p = t.x;
            h.ogt = false;
            --h.x;
            h.d += abs(v[t.x].fi - v[h.x].fi);
            q.push(h);
        }
        {
            ban h = t;
            h.p = t.x;
            h.ogt = false;
            ++h.x;
            h.d += abs(v[t.x].fi - v[h.x].fi);
            q.push(h);
        }
        if (t.x == 0)
            continue;
        int u = a[v[t.x].se].x + a[v[t.x].se].d;
        int i = upper_bound(all(v), m_p(u, 0)) - v.begin();
        {
            ban h = t;
            h.p = t.x;
            h.ogt = true;
            h.x = i;
            h.d += a[v[t.x].se].t;
            h.d += abs(u - v[i].fi);
            q.push(h);
        }
        --i;
        {
            ban h = t;
            h.p = t.x;
            h.ogt = true;
            h.x = i;
            h.d += a[v[t.x].se].t;
            h.d += abs(u - v[i].fi);
            q.push(h);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &a[i].x, &a[i].d, &a[i].t, &a[i].p);
    }
    v.push_back(m_p(0, 0));
    v.push_back(m_p(L, 0));
    for (int i = 1; i <= n; ++i)
    {
        a[i].x -= a[i].p;
        a[i].d += a[i].p;
        a[i].t += a[i].p;
        if (a[i].x >= 0)
            v.push_back(m_p(a[i].x, i));
    }
    sort(all(v));
    printf("%d\n", djk());
    vector<int> ansv;
    for (int i = v.size() - 1; i; i = p[i])
    {
        if (ogt[i])
            ansv.push_back(v[p[i]].se);
    }
    reverse(all(ansv));
    printf("%d\n", ansv.size());
    for (int i = 0; i < ansv.size(); ++i)
        printf("%d ", ansv[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}