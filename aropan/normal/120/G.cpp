#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;


const int MAXN = 101;
const int MAXL = 22;

int n, m, t;
int a[MAXN][2], b[MAXN][2];
int q[MAXN][2];
int d[MAXN][MAXN];
int c[MAXN];
char s[MAXN][MAXL];
vector <int> ans[MAXN];
queue <int> Q;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        q[i][0] = 0;
        q[i][1] = 1;
        scanf("%d %d %d %d", &a[i][0], &b[i][0], &a[i][1], &b[i][1]);
    }

    scanf("%d\n", &m);
    for (int i = 0; i < m; i++)
    {
        gets(s[i]);
        scanf("%d\n", &c[i]);
        Q.push(i);
    }

    for (int iter = 0; Q.size(); iter++)
    {
        int T = t;
        int i = iter % n;
        int fs = q[i][0], sc = q[i][1];
        swap(q[i][0], q[i][1]);

        while (T > 0 && Q.size())
        {
            int x = Q.front();
            Q.pop();

            int res = max(1, c[x] - (a[i][fs] + b[i][sc]) - d[i][x]);

//            printf("%d, %d -> %d word %s(%d) and %d sec for %d", i, a[fs][0], b[sc][1], s[x], c[x], T, res);

            d[i][x] += T;
            T -= res;

//            puts(T < 0? " -" : " +");

            if (T < 0)
                Q.push(x);
            else
                ans[i].push_back(x);
                
        }
    }


    for (int i = 0; i < n; i++)
    {
        printf("%d", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
            printf(" %s", s[ans[i][j]]);
        printf("\n");
    }

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}