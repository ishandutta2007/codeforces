#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

struct ban
{
    int x, y;
    ban *l, *r;
    int i, u, maxu;
    ban() {}
    ban(int x, int y, int i, int u)
    {
        this->x = x;
        this->y = y;
        this->i = i;
        this->u = u;
        this->maxu = u;
        l = r = 0;
    }
};
typedef ban* pban;

int getx(pban t)
{
    if (t == 0)
        return 0;
    return t->x;
}

/*int getu(pban t)
{
    if (t == 0)
        return 0;
    return t->u;
}*/

int getmaxu(pban t)
{
    if (t == 0)
        return 0;
    return t->maxu;
}

void ubd(pban t)
{
    if (t == 0)
        return;
    t->x = getx(t->l) + 1 + getx(t->r);
    t->maxu = max(max(getmaxu(t->l), getmaxu(t->r)), t->u);
}

void spl(pban t, int x, pban& l, pban& r)
{
    if (t == 0)
    {
        l = 0, r = 0;
        return;
    }
    if (getx(t->l) >= x)
    {
        r = t;
        spl(t->l, x, l, r->l);
        ubd(r);
    }
    else
    {
        l = t;
        spl(t->r, x - getx(t->l) - 1, l->r, r);
        ubd(l);
    }
}

void mer(pban l, pban r, pban& t)
{
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
        t = l;
        mer(l->r, r, t->r);
        ubd(t);
    }
    else
    {
        t = r;
        mer(l, r->l, t->l);
        ubd(t);
    }
}

int getfirst(pban t, int u)
{
    if (getmaxu(t->r) > u)
        return getfirst(t->r, u);
    if (t->u > u)
        return getx(t->r) + 1;
    else
        return getfirst(t->l, u) + getx(t->r) + 1;
}

void print(pban t)
{
    if (t == 0)
        return;
    print(t->l);
    printf("%d ", t->i);
    print(t->r);
}

int zz;
int yy[N];

void solv()
{
    for (int i = 0; i < N; ++i)
        yy[i] = i;
    for (int i = N - 1; i >= 0; --i)
    {
        swap(yy[i], yy[rnf() % (i + 1)]);
    }
    int n;
    scanf("%d", &n);
    pban t = 0;
    for (int i = 1; i <= n; ++i)
    {
        int u, x;
        scanf("%d%d", &u, &x);
        if (t == 0)
        {
            t = new ban(1, yy[zz++], i, u);
        }
        else
        {
            x = min(x, t->x);
            pban l, r;
            spl(t, t->x - x, l, r);
            if (getmaxu(r) < u)
            {
                mer(l, new ban(1, yy[zz++], i, u), t);
                mer(t, r, t);
            }
            else
            {
                mer(l, r, t);
                x = getfirst(t, u);
                --x;
                spl(t, t->x - x, l, r);
                mer(l, new ban(1, yy[zz++], i, u), t);
                mer(t, r, t);
            }
        }
    }
    print(t);
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