#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2007;
const int MAXQ = MAXN * MAXN;
const double INF = 1e+20;

template <typename T> T sqr(T x) { return x * x; }

int a[MAXN][MAXN];
bool f[MAXN][MAXN];
int n;
pair <int, int> q[MAXQ];
int q1, q2;
int ansk, ansc;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		if (a[i][j])
    		{
				for (int dx = -1; dx <= 1; dx++)
    				for (int dy = -1 + (int)(dx != 0); dy <= 1; dy += 2)
    				{
    					int
    						x = i + dx,
    						y = j + dy;
						if (0 <= x && x < n && 0 <= y && y < n && a[x][y] == 0)
						{
							f[i][j] = true;
							break;
						}
    				}
    		}
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		if (a[i][j])
    		{
    			q1 = q2 = 0;
    			a[i][j] = 0;
    			q[q1++] = make_pair(i, j);
    			while (q1 != q2)
    			{
    				int
    					x = q[q2].first,
    					y = q[q2].second;
    				q2++;

    				for (int dx = -1; dx <= 1; dx++)
    					for (int dy = -1; dy <= 1; dy++)
    					{
    						x += dx;
    						y += dy;
    						if (0 <= x && x < n && 0 <= y && y < n && a[x][y])
    						{
    							a[x][y] = 0;
    							q[q1++] = make_pair(x, y);
    						}
    						x -= dx;
    						y -= dy;
    					}
    			}
    			double x, y;
    			x = y = 0;
    			int m = q1;
    			for (int k = 0; k < m; k++)
    			{
    				x += q[k].first;
    				y += q[k].second;
    			}

    			x = x / m;
    			y = y / m;

    			double
    				minl = INF,
    				maxl = -INF;

    			for (int k = 0; k < m; k++)
    			{
    				if (!f[q[k].first][q[k].second]) continue;
    				double l = sqrt(sqr(q[k].first - x) + sqr(q[k].second - y));
    				if (l < minl) minl = l;
    				if (l > maxl) maxl = l;
    			}

    			if (fabs(minl - maxl) < 3)
    				ansc++;
    			else
    				ansk++;
//    			printf("%.3lf %.3lf\n", minl, maxl);
    		}
    printf("%d %d\n", ansc, ansk);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}