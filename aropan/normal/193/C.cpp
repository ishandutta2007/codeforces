#include <cstdio>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 10;
const long double EPS = 1e-9;

double a[MAXN][MAXN];
double x[MAXN];
int answer[MAXN], X[MAXN];
int ans;
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif


    for (int i = 1; i < 8; i++)
    {
    	int v[4];
    	for (int j = 0; j < 4; j++)
    		v[j] = (i & (1 << (3 - j))) != 0;
    	int k = 0;
    	for (int x = 0; x < 4; x++)
    		for (int y = x + 1; y < 4; y++)
    			a[k++][i - 1] = (int)(v[x] != v[y]);
    }         



    n = 6;
    m = 7;

    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
    	cin >> a[i][m];
    	ans += (int)a[i][m] + 1;
    }

    int p[MAXN];
    for (int i = 0; i <= m; i++)
    	p[i] = i;


    for (int I = 0; I < n; I++)
    {
    	for (int j = I; j < m; j++)
    		if (fabs(a[I][p[I]]) < fabs(a[I][p[j]]))
    			swap(p[I], p[j]);

    	for (int i = I + 1; i < n; i++)
    	{
  			long double c = a[i][p[I]] / a[I][p[I]];
    		for (int j = m; j >= I; j--)
    			a[i][p[j]] -= a[I][p[j]] * c;
    	}
/*
        for (int i = 0; i < n; i++)
        {
        	for (int j = 0; j <= m; j++)
        		printf(" %0.3lf", a[i][p[j]]);
        	printf("\n");
        }
        printf("\n");
        fflush(stdout);
//*/
    }


    bool flag = false;
    for (int iter = 0; iter <= ans; iter++)
    {
    	x[p[m - 1]] = iter;
    	for (int i = n - 1; i >= 0; i--)
    	{
    		long double s = 0;
    		for (int j = i + 1; j < m; j++)
    			s += x[p[j]] * a[i][p[j]];
    		x[p[i]] = (a[i][p[m]] - s) / a[i][p[i]];
    	}


    	for (int i = 0; i < m; i++)
    		answer[i] = (int)(x[i] + 0.5);

    	bool f = true;
    	for (int i = 0; i < m; i++)
    		f &= (x[i] > -EPS) && (fabs(answer[i] - x[i]) < EPS) && (x[i] - EPS < ans);
    	if (!f) continue;

    	int res = 0;
    	for (int i = 0; i < m; i++)
    		res += answer[i];
/*
    	for (int i = 0; i < m; i++)
    		printf("%d ", answer[i]);
    	printf("\n");
//*/
    	if (res >= ans) continue;

    	flag = true;
    	memmove(X, answer, sizeof(X));

    	ans = res;

    }

    if (!flag)
    {
    	puts("-1");
    	return 0;
    }

    printf("%d\n", ans);
    for (int i = 0; i < 4; i++)
    {
    	for (int j = 0; j < m; j++)
    		for (int x = X[j]; x; x--)
    			printf("%c", ((j + 1) & (1 << (3 - i))) == 0? 'a' : 'b');
    	printf("\n");
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}