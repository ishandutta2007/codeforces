#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <queue>

#define sqr(x) ((x)*(x))

#define X first
#define Y second

using namespace std;


const int MAXN = 100001;

pair <int, int> a[MAXN];
int t[MAXN];
int d[MAXN], _d[MAXN];
int n, m;

double ans;
pair <int, int> answer;

bool opr_sort(const int &i, const int &j)
{
    return a[i] < a[j];
}


inline bool lq(const double a, const double b)
{
    return a < b || fabs(a - b) < 1e-9;
}


inline void check(const int i, const int j)
{
    double l = sqrt(sqr(a[i].X - a[j].X) + sqr(a[i].Y - a[j].Y));
    if (l < ans)
    {
        ans = l;
        answer = make_pair(i, j);
    }
}


int merge(int l, int r)
{
    if (l == r) return 0;

    int c = (r + l) / 2;
    double x = (double)(a[d[c]].X + a[d[c + 1]].X) / 2;

    merge(l, c);
    merge(c + 1, r);


    queue <int> ql, qr;
    while (ql.size()) ql.pop();
    while (qr.size()) qr.pop();
/*
    printf("x: %.6lf\n", x);
    printf("L:\n");
    for (int i = l; i <= c; i++)
        printf("\t%d %d\n", a[d[i]].X, a[d[i]].Y);
    printf("R:\n");
    for (int i = c + 1; i <= r; i++)
        printf("\t%d %d\n", a[d[i]].X, a[d[i]].Y);
    printf("\n");
//*/

    int i = l, j = c + 1;
    int k = l;
    while (i <= c || j <= r)
    {
        if (i <= c && (r < j || a[d[i]].Y <= a[d[j]].Y))
        {
            int s = qr.size();
            for (int z = 0; z < s; z++)
            {
                int p = qr.front();
                qr.pop();

                if (lq(fabs(a[p].X - x), ans) && lq(fabs(a[p].Y - a[d[i]].Y), ans))
                {
                    qr.push(p);
                    check(d[i], p);
                }
            }

            ql.push(d[i]);
            _d[k++] = d[i++];
        }
        else
        {
            int s = ql.size();
            for (int z = 0; z < s; z++)
            {
                int p = ql.front();
                ql.pop();

                if (lq(fabs(a[p].X - x), ans) && lq(fabs(a[p].Y - a[d[j]].Y), ans))
                {
                    ql.push(p);
                    check(d[j], p);
                }
            }

            qr.push(d[j]);
            _d[k++] = d[j++];
        }
    }

    for (int i = l; i <= r; i++)
        d[i] = _d[i];

    return 0;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].X, &a[i].Y);
        if (a[i].X < 0) a[i].X = -a[i].X, t[i] ^= 1;
        if (a[i].Y < 0) a[i].Y = -a[i].Y, t[i] ^= 2;
        d[i] = i;
    }
    sort(d, d + n, opr_sort);
    ans = 1e+60;
    merge(0, n - 1);

//    printf("%.6lf\n", ans);
    printf("%d %d %d %d\n", answer.X + 1, t[answer.X] + 1, answer.Y + 1, (t[answer.Y] ^ 3) + 1);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}