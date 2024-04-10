#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

#define dx first
#define dy second
#define mp make_pair
#define pb push_back

using namespace std;

vector < pair <int, int> > a;
vector < pair <int, int> > s;

//char c[1025][1025];

pair <int, int> right(pair <int, int> v)
{
    return mp(v.dy, -v.dx);
}

pair <int, int> left(pair <int, int> v)
{
    return mp(-v.dy, v.dx);
}

pair <int, int> rev(pair <int, int> v)
{
    return mp(-v.dx, -v.dy);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            a = s;
            s.pb(mp(1, 0));
            for (vector < pair <int, int> > :: iterator iter = a.end(); iter-- != a.begin(); ) s.pb(right(rev(*iter)));
            s.pb(mp(0, 1));
            for (vector < pair <int, int> > :: iterator iter = a.end(); iter-- != a.begin(); ) s.pb(right(rev(*iter)));
            s.pb(mp(-1, 0));
            for (vector < pair <int, int> > :: iterator iter = a.begin(); iter != a.end(); ++iter) s.pb(rev(*iter));
        }
        else
        {
            a = s;
            s.pb(mp(0, 1));
            for (vector < pair <int, int> > :: iterator iter = a.end(); iter-- != a.begin(); ) s.pb(left(rev(*iter)));
            s.pb(mp(1, 0));
            for (vector < pair <int, int> > :: iterator iter = a.end(); iter-- != a.begin(); ) s.pb(left(rev(*iter)));
            s.pb(mp(0, -1));
            for (vector < pair <int, int> > :: iterator iter = a.begin(); iter != a.end(); ++iter) s.pb(rev(*iter));
        }
    }
    int x, y;
    x = y = 0;
    for (int i = 0; i < m; i++)
    {
        x += s[i].dx;
        y += s[i].dy;
    }
    if (n & 1)
        swap(x, y);
    printf("%d %d\n", x, y);
/*
    memset(c, ' ', sizeof(c));

    x = y = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        c[x][y] = '*';
        x += s[i].dx;
        y += s[i].dy;
        c[x][y] = '*';
        x += s[i].dx;
        y += s[i].dy;
    }

    for (int i = 0; i < 1024; i++, printf("\n"))
        for (int j = 0; j < 1024; j++)
            printf("%c", c[i][j]);
//*/
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}