#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, q;
char a[N];

struct ban
{
    int z, m;
    int ans, sans;
    int laz;
};

ban t[N * 4];

void mer(int pos)
{
    t[pos].z = t[pos * 2].z + t[pos * 2 + 1].z;
    t[pos].m = t[pos * 2].m + t[pos * 2 + 1].m;
    t[pos].ans = max(t[pos * 2].ans + t[pos * 2 + 1].m, t[pos * 2].z + t[pos * 2 + 1].ans);
    t[pos].sans = max(t[pos * 2].sans + t[pos * 2 + 1].z, t[pos * 2].m + t[pos * 2 + 1].sans);
}

void shi(int pos)
{
    if (t[pos].laz == 0)
        return;
    t[pos * 2].laz ^= t[pos].laz;
    swap(t[pos * 2].z, t[pos * 2].m);
    swap(t[pos * 2].ans, t[pos * 2].sans);

    t[pos * 2 + 1].laz ^= t[pos].laz;
    swap(t[pos * 2 + 1].z, t[pos * 2 + 1].m);
    swap(t[pos * 2 + 1].ans, t[pos * 2 + 1].sans);

    t[pos].laz = 0;
}

void bil(int tl, int tr, int pos)
{
    t[pos].laz = 0;
    if (tl == tr)
    {
        if (a[tl - 1] == '4')
        {
            t[pos].z = 1;
            t[pos].m = 0;
            t[pos].ans = 1;
            t[pos].sans = 1;
        }
        else
        {
            t[pos].z = 0;
            t[pos].m = 1;
            t[pos].ans = 1;
            t[pos].sans = 1;
        }
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    mer(pos);
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos].laz ^= 1;
        swap(t[pos].z, t[pos].m);
        swap(t[pos].ans, t[pos].sans);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, pos * 2);
        ubd(m + 1, tr, m + 1, r, pos * 2 + 1);
    }
    mer(pos);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> a;
    bil(1, n, 1);
    while (q--)
    {
        char ty[10];
        cin >> ty;
        if (ty[0] == 'c')
        {
            cout << t[1].ans << endl;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ubd(1, n, l, r, 1);
        }
    }
    return 0;
}