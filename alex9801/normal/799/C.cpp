#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct str
{
    int b, c;
    bool operator <(const str &a) const
    {
        return c != a.c ? c < a.c : b > a.b;
    }
};

vector<str> vc, vd, tmp, oc, od;

int main()
{
    int n, c, d, b, p, r, t, pp, qq, x, i;
    char tt;
    scanf("%d%d%d", &n, &c, &d);
    for(i = 0; i<n; i++)
    {
        scanf("%d%d %c", &b, &p, &tt);
        if(tt == 'C')
            vc.push_back({ b, p });
        else
            vd.push_back({ b, p });
    }

    sort(vc.begin(), vc.end());
    sort(vd.begin(), vd.end());

    t = -1;
    for(str &e: vc)
    {
        if(e.b <= t)
        {
            oc.push_back(e);
            continue;
        }
        t = e.b;
        tmp.push_back(e);
    }
    swap(vc, tmp);
    tmp.clear();

    t = -1;
    for(str &e: vd)
    {
        if(e.b <= t)
        {
            od.push_back(e);
            continue;
        }
        t = e.b;
        tmp.push_back(e);
    }
    swap(vd, tmp);
    tmp.clear();

    reverse(vc.begin(), vc.end());
    reverse(vd.begin(), vd.end());

    bool u = 0;
    r = 0;
    for(str &e: vc)
    {
        if(e.c <= c)
        {
            r += e.b;
            u = 1;
            break;
        }
    }

    if(u)
    {
        u = 0;
        for(str &e: vd)
        {
            if(e.c <= d)
            {
                r += e.b;
                u = 1;
                break;
            }
        }
        if(!u)
            r = 0;
    }
    else
        r = 0;

    for(str &e: oc)
    {
        pp = 0;
        qq = vc.size() - 1;
        while(pp < qq)
        {
            x = (pp + qq) / 2;
            if(vc[x].c + e.c > c)
                pp = x+1;
            else
                qq = x;
        }
        if(0<=pp && pp<vc.size() && vc[pp].c + e.c <= c)
            r = max(r, e.b + vc[pp].b);
    }

    for(str &e: od)
    {
        pp = 0;
        qq = vd.size() - 1;
        while(pp < qq)
        {
            x = (pp + qq) / 2;
            if(vd[x].c + e.c > d)
                pp = x+1;
            else
                qq = x;
        }
        if(0<=pp && pp<vd.size() && vd[pp].c + e.c <= d)
            r = max(r, e.b + vd[pp].b);
    }

    pp = 0;
    qq = vc.size() - 1;
    while(pp < qq)
    {
        while(pp < vc.size() && vc[pp].c + vc[qq].c > c)
            pp++;

        if(pp >= qq)
            break;

        r = max(r, vc[pp].b + vc[qq].b);
        qq--;
    }

    pp = 0;
    qq = vd.size() - 1;
    while(pp < qq)
    {
        while(pp < vd.size() && vd[pp].c + vd[qq].c > d)
            pp++;

        if(pp >= qq)
            break;

        r = max(r, vd[pp].b + vd[qq].b);
        qq--;
    }

    printf("%d", r);
    return 0;
}