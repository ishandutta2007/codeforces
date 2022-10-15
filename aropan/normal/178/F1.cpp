#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2007;

int n, m;
int g[MAXN][MAXN];
string s[MAXN];
int p[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
	cin >> n >> m;
    for (int i = 0; i < n; i++)
    	cin >> s[i];
    sort(s, s + n);

    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
    	{
    		int x = 0;
    		while (x < (int)s[i].size() && x < (int)s[j].size() && s[i][x] == s[j][x]) x++;
//    		printf("%d %d %d\n", i, j, x);
    		g[j][i] = g[i][j] = x;

    	}

    for (int i = 0; i < m; i++)
    	p[i] = 1;
    sort(p, p + n);

    int ans = 0;
    do
    {
    	int res = 0;
    	for (int i = 0; i < n; i++)
    		for (int j = i + 1; j < n; j++)
    			if (p[i] && p[j])
    				res += g[i][j];
		ans = max(res, ans);
    } while (next_permutation(p, p + n));
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}