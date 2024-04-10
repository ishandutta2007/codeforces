#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define sqr(x) ((x)*(x))

using namespace std;


#define X first
#define Y second

const int MAXN = 8;

pair <int, int> p[MAXN];
int a[MAXN], b[MAXN];

bool getL(int a[MAXN], vector <int> &l)
{
    l.clear();
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            l.push_back(sqr(p[a[i]].X - p[a[j]].X) + sqr(p[a[i]].Y - p[a[j]].Y));
    sort(l.begin(), l.end());
}


bool check(int a[MAXN])
{
    for (int i = 0; i < 4; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
            if (i != j)
            {
                int
                    A = p[a[j]].Y - p[a[i]].Y,
                    B = p[a[i]].X - p[a[j]].X,
                    C = -(A * p[a[i]].X + B * p[a[i]].Y);
                int l, r;
                l = r = 0;

                for (int k = 0; k < 4; k++)
                    if (k != i && k != j)
                    {
                        int x = A * p[a[k]].X + B * p[a[k]].Y + C;
                        if (x <= 0) l++;
                        if (0 <= x) r++;
                    }
                if (l == 0 || r == 0)
                {
                    flag = true;
                    break;
                }
            }
        if (!flag) return true;
    }
    return false;
}

bool checkrect(int a[MAXN])
{
    if (check(a)) return false;
    vector <int> l;
    getL(a, l);

    return l[0] == l[1] && l[2] == l[3] && l[4] == l[5];
}

bool checksqure(int a[MAXN])
{
    if (check(a)) return false;
    vector <int> l;
    getL(a, l);

    return l[0] == l[1] && l[1] == l[2] && l[2] == l[3] && l[4] == l[5];
}

int rec(int n, int m)
{
    if (n + m == 8)
    {
        if (checkrect(a) && checksqure(b))
        {
            puts("YES");
            for (int i = 0; i < 4; i++)
            {
                if (i) printf(" ");
                printf("%d", b[i] + 1);
            }
            printf("\n");
            for (int i = 0; i < 4; i++)
            {
                if (i) printf(" ");
                printf("%d", a[i] + 1);
            }
            printf("\n");
            exit(0);
        }
        return 0;
    }

    int t = n + m;
    if (n < 4)
    {
        a[n] = t;
        rec(n + 1, m);
    }
    if (m < 4)
    {
        b[m] = t;
        rec(n, m + 1);
    }
    return 0;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    for (int i = 0; i < 8; i++)
        scanf("%d %d", &p[i].X, &p[i].Y);

    rec(0, 0);
    puts("NO");
    return 0;
}