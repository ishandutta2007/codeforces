#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstring>
#include <algorithm>

#define y1 Y1

using namespace std;

template <typename T> T sqr(T x) { return x * x; }

const int MAXN = 1024;

struct segment
{
	int x1, y1, x2, y2;
	segment(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) { }
};

int A, B;
int n;
int x1, y1, x2, y2;
segment a[MAXN];
double d[MAXN][MAXN];
priority_queue < pair <double, int> > h;
double f[MAXN];

double L(int x1, int y1, int x2, int y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double G(const segment &a, int x, int y)
{
	double res = min(L(a.x1, a.y1, x, y), L(a.x2, a.y2, x, y));
	if (a.x1 <= x && x <= a.x2) res = min(res, fabs(a.y1 - y));
	if (a.y1 <= y && y <= a.y2) res = min(res, fabs(a.x1 - x));
	return res;
}

double F(const segment &a, const segment &b)
{
	return
    	min(	
    		min(
    			G(a, b.x1, b.y1),
    			G(a, b.x2, b.y2)
    		),
    		min(
    			G(b, a.x1, a.y1),
    			G(b, a.x2, a.y2)
    		)
    	);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d %d %d %d %d", &A, &B, &x1, &y1, &x2, &y2, &n);
    for (int i = 0; i < n; i++)
    {
    	scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    	if (a[i].x1 > a[i].x2) swap(a[i].x1, a[i].x2);
    	if (a[i].y1 > a[i].y2) swap(a[i].y1, a[i].y2);
    }
    a[n++] = segment(x1, y1, x1, y1);
    a[n++] = segment(x2, y2, x2, y2);


    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
    		d[j][i] = d[i][j] = F(a[i], a[j]);

    for (int i = 0; i < n; i++)
    	f[i] = 1e+30;

    f[n - 2] = 0;
    h.push(make_pair(-0.0, n - 2));
    while (h.size())
    {
    	int x = h.top().second;
    	double l = -h.top().first;
    	h.pop();
    	if (x == n - 1) continue;
    	if (fabs(f[x] - l) > 1e-9) continue;

    	for (int i = 0; i < n; i++)
    		if (d[x][i] < A + 1e-9 && f[x] + (i == n - 1? d[x][i] : A + B) < f[i])
    		{
    			f[i] = f[x] + (i == n - 1? d[x][i] : A + B);
    			h.push(make_pair(-f[i], i));
    		}
    }

    if (f[n - 1] > 1e+20)
    	puts("-1");
    else
    	printf("%.7lf\n", f[n - 1]);
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}